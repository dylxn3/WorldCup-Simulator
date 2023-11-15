#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>

struct teams{
    int teamcode;
    char teamName[26];
    char groupseed[3];
    char teamcolor; 
}teaminfo;

struct node{
    int teamcode;
    char teamName[26];
    char groupseed[3];
    char teamcolor; 
    struct node *next;

};
struct node* first;

struct node *add_to_list(struct node *list, int code,char name[26],char groupseed[3],
 char teamcolor ){
    

    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->teamcode = code;
    strcpy(new_node->teamName, name);
    strcpy(new_node->groupseed, groupseed);
    new_node->teamcolor = teamcolor;
    
    new_node->next = list;

    list = new_node;

    printf("%d\n", new_node->teamcode);
    printf("%s\n", new_node->teamName);
    printf("%s\n", new_node->groupseed);
    printf("%c\n", new_node->teamcolor);
    return list;
    }


void getTeam( char command, struct node *node){
    
    
    struct node *new_node;
    new_node =  malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        return;
        }
    int code;
    int teamCode;
    char seed[3];
    char name[26];
    char teamColor;
    bool flag1;
   
    // prompt for the event code only when the operation is insert
    if (command == 'i') {
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
            if(reference1->teamcode == code){
                printf("Team code in use");
                return;
            }
            reference1 = reference1-> next;
            

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
            reference2 = reference2-> next;
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
            if(reference3->groupseed == seed){
                printf("Group seed taken");
                return;
            }
            reference3 = reference3-> next;
            

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

    strcpy(teaminfo.teamName, name);
    strcpy(teaminfo.groupseed, seed);
    teaminfo.teamcode = teamCode;
    teaminfo.teamcolor = teamColor;
    //printf("%s",teaminfo.teamName);

    node = add_to_list(node,teaminfo.teamcode,teaminfo.teamName,teaminfo.groupseed,teaminfo.teamcolor);
    
    

     
    
}
print(struct node* first){
    struct node *reference = first; 
    printf("%-15s%-50s%-25s%-15s\n", "Team Code", "Team Name", "Groupseed", "Uniform Color");
    while(reference != NULL){
        printf("%-15d%-50s%-25s%-15c\n", reference->teamcode,reference->teamName,
        reference->groupseed,reference->teamcolor);
        reference = reference ->next;
    }
    return;
}

int main(){
    char command;
    struct node* first;
    //first = malloc(sizeof(struct node));
   

    // display the title
    printf("*************************\n");
    printf("* 2211 World Cup! *\n");
    printf("*************************\n");

    // continuously prompt the user for one of five possible commands
    for(;;){
        printf("Enter command code: ");
        scanf(" %c", &command);
        while (getchar() != '\n'); /* skips to end of line */

        switch (command) {
        case 'i': getTeam(command, first);
            //printf("%s",first->teamcode);
            break;
        //case 's': search();
            //break;
        //case 'u': update();
            //break;
        case 'p': print(first);
            break;
        //case 'q': return 0;
            //default: printf("Illegal code\n");
    }
   
    }
}
