#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// a structure that hold the teams info
struct DATA
{
    int teamCode;
    char groupSeed[3];
    char teamName[26];
    char teamColor;
};

// helper method to dictate if existing team exists 
bool getTeam(struct DATA *newTeam, struct DATA teams[], int slots, char command)
{
    // required variables
    int code;
    int teamCode;
    char groupSeed[3];
    char teamName[26];
    char teamColor;
    // prompt for the event code only when the operation is insert
    if (command == 'i') {
        // Prompt the user for the event code
        printf("Enter team code: ");
        scanf("%d", &code);
        teamCode = code;
        //printf("%d", code);     //used to debug
        //printf("%d", teamCode);



        // check if the number is within the given range
        if (teamCode < 0 || teamCode> 31)
        {
            printf("The team code should only be numbers 0-31!\n");
            return false;
        }
                
        // check if the code exists in the database
        for (int i = 0; i < slots; i++)
        {
            // if a event is found in the database
            if (teams[i].teamCode == teamCode)
            {
                // print an error message and go to the beginning
                printf("Team already exists.\n");
                return  false;
            }
        }
    }
    

    fflush(stdin);
    // asks for name of team
    printf("\tEnter team name: ");
    scanf("%25s", teamName);
    int length = strlen(teamName);
    // finds each team name
    for (int i = 0; i< slots;i++){
         if (teams[i].teamName[0] == teamName[0] && teams[i].teamName[1] == teamName[1]
         &&teams[i].teamName[2] == teamName[2] && teams[i].teamName[3] == teamName[3] ){
            printf("Team name already exists");
            return false;
                
        }
        

    }

    fflush(stdin);
    // asks user for the group seed 
    printf("Enter the group seed of the team: \n");//have to configure
    //fflush(stdout);
    scanf("%3s", groupSeed);
    

    if (groupSeed[0]== 'A'||groupSeed[0]== 'B'||groupSeed[0]== 'C'||groupSeed[0]== 'D'||groupSeed[0]== 'E'||groupSeed[0]== 'F'||
        groupSeed[0]== 'G'||groupSeed[0]== 'H'){
        if (groupSeed[1]== '1'||groupSeed[1]== '2'||groupSeed[1]== '3'||groupSeed[1]== '4')
            printf("");
        }
    // error if the group seed isnt proper synthax
    else{
        printf("Group seed must be consists of letters A-H and numbers 1-4 ONLY!\n");
        return false;
    }
    for (int i = 0; i< slots;i++){
        if (teams[i].groupSeed[0] == groupSeed[0] && teams[i].groupSeed[1] == groupSeed[1]){
            printf("Seed already in use");
            return false;
                }
    }
    
    getchar();
    // Prompt the user for the uniform color of the team
    printf("Enter the uniform color: \n");
    scanf("%c", &teamColor);
    if (teamColor == 'R' ||teamColor == 'O'||teamColor == 'Y'||teamColor == 'G'||teamColor == 'B'||teamColor == 'I'||teamColor == 'V'){
        printf("");
        
    }
    else{
        printf("Invalid uniform color, try again!\n");
        return false; 
    }

    // saves the team in the data base
    strncpy(newTeam->teamName, teamName, 23);
    strncpy(newTeam->groupSeed, groupSeed,2);
    newTeam->teamCode = teamCode;
    newTeam->teamColor = teamColor;

    // return true if there are no conflicts with an existing team 
    return true;
}

// main function
int main(){

    char command;
    int slots = 0; //counter fo number of teams
    

    // create an array of structures
    struct DATA teams[32];

    // display the title
    printf("*************************\n");
    printf("* 2211 World Cup! *\n");
    printf("*************************\n");

    // continuously prompt the user for one of five possible commands
    do 
    {
        // get the new command
        printf("\nEnter command code: ");
        scanf(" %c", &command);

        // if the user decides to insert a new  team
        if(command == 'i')
        {
            // check if the database is full
            if (slots >= 32){
                printf("The database is full, so no new team can be added!\n");
                continue;
            }
            
            // invoke the helper method 
            struct DATA newteam;
            bool check = getTeam(&newteam, teams, slots, command);
            if (check == false){
                printf("");

            }
            
            
                // add the team to the array
                teams[slots] = newteam;
                // increment the number of teams i
                slots++;
            }
        }
        // if user chooses to display team details
        else if (command == 'p')
        {
            // print the headers
            printf("%-15s%-50s%-25s%-15s\n", "Team Code", "Team Name", "Groupseed", "Uniform Color");
            // loop through teams details
            for (int i = 0; i < slots; i++)
                if(teams[i].teamColor == 'R'){
                    printf("%-15d%-50s%-25sRed\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                }
                else if(teams[i].teamColor == 'Y'){
                    printf("%-15d%-50s%-25sYellow\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                }
                 else if(teams[i].teamColor == 'I'){
                    printf("%-15d%-50s%-25sIndigo\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                }
                 else if(teams[i].teamColor == 'B'){
                    printf("%-15d%-50s%-25sBlue\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                }
                 else if(teams[i].teamColor == 'G'){
                    printf("%-15d%-50s%-25sGreen\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                }
                 else if(teams[i].teamColor == 'V'){
                    printf("%-15d%-50s%-25sViolet\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                }
                 else if(teams[i].teamColor == 'O'){
                    printf("%-15d%-50s%-25sOrange\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                }
                
        }
        // if user chooses to update a teams details
        else if (command== 'u')
        {
            bool flag = false;
            int teamcode;
            
            // ask for team code to check if in system
            printf("\tEnter team code: ");
            scanf("%d", &teamcode);

            // loop through teams
            for (int i = 0; i < slots; i++)
            {
                // If the team code is found
                if (teams[i].teamCode == teamcode)
                {
                    flag = true;
                    // use helper method
                    struct DATA newteam;
                    bool check = getTeam(&newteam, teams, slots, command);
                    // change the old teams details to the users new details
                    if (check == true)
                        teams[i] = newteam;
                    
                    
                    break;
                }
            }
            // display an error message if the given code in not found in the database
            if (!flag)
                printf("Team Code not found.\n");
        }

        // else if the user decides to search for an team
        else if (command == 's')
        {   bool flag = false;
            int teamCode;
            
            //ask for team code to search in data
            printf("Enter team Code: ");
            scanf("%d", &teamCode);

            // loop through teams
            for (int i = 0; i < slots; i++)
            {

                // when existing team is found 
                if (teams[i].teamCode == teamCode)
                {
                    flag = true;
                    // print the teams headers
                    printf("%-15s%-50s%-25s%-15s\n", "Team Code", "Team Name", "Groupseed", "Uniform Color");
                    if(teams[i].teamColor == 'R'){
                        printf("%-15d%-50s%-25sRed\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                    }
                    else if(teams[i].teamColor == 'Y'){
                        printf("%-15d%-50s%-25sYellow\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                    }
                     else if(teams[i].teamColor == 'I'){
                        printf("%-15d%-50s%-25sIndigo\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                    }
                     else if(teams[i].teamColor == 'B'){
                        printf("%-15d%-50s%-25sBlue\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                    }
                     else if(teams[i].teamColor == 'G'){
                        printf("%-15d%-50s%-25sGreen\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                    }
                    else if(teams[i].teamColor == 'V'){
                        printf("%-15d%-50s%-25sViolet\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                    }
                    else if(teams[i].teamColor == 'O'){
                        printf("%-15d%-50s%-25sOrange\n", (int)teams[i].teamCode, teams[i].teamName, teams[i].groupSeed);
                    }
                    

                    break;
                }
            }

            // if team code not found, display a error message
            if (!flag)
                printf("Team Code not found in system.\n");
        }
        
        // else if the user decides to quit
        else if (command== 'q')
            printf("Exiting...Goodbye!\n");

        // else an invalid operation code is entered
        else
            printf("Invalid command code! Try again\n");
    } 
    while (command != 'q'); // loop tillt he use selects to quit
    return 0;
}

