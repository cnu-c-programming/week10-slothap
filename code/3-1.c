#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int score;
    struct Node* next;
};

struct Node* head = NULL;

void add(char* name, int score){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode -> name, name);
    newNode -> score = score;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* pre = head;
        while( pre -> next != NULL){
            pre = pre -> next;
        }
        pre -> next = newNode;
    }
    
}

void delete(char *name){
    // if (head == NULL) return 0;

    if(strcmp(head -> name, name) == 0){
        struct Node* temp = head;
        head = head -> next;
        free(temp);
        return;
    }

    struct Node* cur = head;
    while (cur -> next != NULL && strcmp(cur -> next -> name, name) != 0){
        cur = cur -> next;
    }

    struct Node* temp = cur -> next;
    cur -> next = cur -> next -> next;
    free(temp);
}

void print() {
    struct Node* cur = head;
    while(cur != NULL){
        printf("%s %d\n", cur -> name, cur -> score);
        cur = cur -> next;
    }
}

void quit(){
    struct Node* cur = head;
    while(cur != NULL){
        struct Node* temp = cur;
        cur = cur -> next;
        free(temp);
    }
}

int main() {
    char command[10];
    char name[50];
    int score;

    while (1) {
        //커맨드 입력 받고 -> 따로따로 함수 실행
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        }
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        }
        else if (strcmp(command, "print") == 0) {
            print();
        }
        else if (strcmp(command, "quit") == 0) { 
            quit();
            break;
        }
    }
    return 0;
}