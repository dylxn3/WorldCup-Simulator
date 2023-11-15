#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>

struct teams{
    int teamcode;
    char teamName[26];
    char groupseed[3];
    char teamcolor; 
};

struct node{
    int teamcode;
    char teamName;
    char groupseed;
    char teamcolor; 
    struct node *next;

};


void getTeam( char command, struct node *node)
{
    bool flag = true;
    struct node *new_node;
    new_node = (struct node*) malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        flag = false;
        return;
        }
    int code;
    int teamCode;
    char seed[3];
    char name[26];
    char teamColor;
    bool flag1;
    // prompt for the event code only when the operation is insert
    if (command == "i") {
        // Prompt the user for the event code
        printf("Enter team code: ");
        scanf("%d", &code);
        teamCode = code;

        if(teamCode<0 ){
            printf("Team code must be greater than 0");
            return;
            
            
        }
        struct node *reference1 = node; 
        while(reference1 != NULL){
            if(reference1->teamcode == code);
            printf("Team code in use");
            return;
            

        }
    }
    fflush(stdin);
    printf("Enter team name: ");
    scanf("%25s", name);  
    struct node *reference2 = node; 
        while(reference2 != NULL){
            if(reference2->teamName == name){
                printf("Team name taken\n");
                return;
            }
        }
    fflush(stdin);
    // asks user for the group seed 
    printf("Enter the group seed of the team: \n");//have to configure
    //fflush(stdout);
    scanf("%3s", seed);
    if (seed[0]== 'A'||seed[0]== 'B'||seed[0]== 'C'||seed[0]== 'D'||seed[0]== 'E'||seed[0]== 'F'||
        seed[0]== 'G'||seed[0]== 'H'){
        if (seed[1]== '1'||seed[1]== '2'||seed[1]== '3'||seed[1]== '4')
            printf("");
        }
    // error if the group seed isnt proper synthax
    else{
        printf("Group seed must be consists of letters A-H and numbers 1-4 ONLY!\n");
        return;
        
    }
    struct node *reference3 = node; 
        while(reference3 != NULL){
            if(reference3->groupseed == seed);
            printf("Group seed taken");
            return;
            

        }

    getchar();
    printf("Enter the uniform color: \n");
    scanf("%c", &teamColor);
    if (teamColor == 'R' ||teamColor == 'O'||teamColor == 'Y'||teamColor == 'G'||teamColor == 'B'||teamColor == 'I'||teamColor == 'V'){
        printf("");
        
    }
    else{
        printf("Invalid uniform color, try again!\n");
        return;
        
    }

    // allocate memory for each value type
    new_node->teamcode= malloc(sizeof(teamCode)+1);
    new_node->teamcolor=malloc(strlen(teamColor)+1);
    new_node->groupseed= malloc(strlen(seed)+1);
    new_node ->teamName = malloc(strlen(name)+2);

    // insert into node;
     new_node->teamcode = teamCode;
     new_node->teamcolor = teamColor;
     new_node->groupseed = seed;
     new_node ->teamName = name;
     return;
     
    
}

int main(){
    char command;
    struct node* first = NULL;

    // display the title
    printf("*************************\n");
    printf("* 2211 World Cup! *\n");
    printf("*************************\n");

    // continuously prompt the user for one of five possible commands
    for(;;){
        printf("Enter command code:");
        scanf(" %c", &command);
        while (getchar() != '\n'); /* skips to end of line */

        switch (command) {
        case 'i': getTeam(command, first);
            break;
        //case 's': search();
            //break;
        //case 'u': update();
            //break;
        //case 'p': print();
            //break;
        //case 'q': return 0;
            //default: printf("Illegal code\n");
    }
   
    }
}
