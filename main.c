#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int main(void){
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL){
        printf("Could not open current directory" );
        return 0;
    }
    int numOfFiles = 0;
    while ((de = readdir(dr)) != NULL){
        char* str = de->d_name;
        if (str[0] == 'i' && str[1] == 'n' && str[2] == 'p' && str[3] == 'u' && str[4] == 't') {
            numOfFiles++;
        }
    }
    if (numOfFiles > 50) {
        numOfFiles = 50;
    }
    closedir(dr);

    struct proff{
        char* name;
        char trained[1000][100];
        int coursesAvaliable;
    };

    struct TA{
        char* name;
        char trained[1000][100];
        int coursesAvaliable;
    };

    struct course{
        char* name;
        int numOfStudents;
        int numOfLabs;
    };
    for (size_t iterator = 1; iterator <= numOfFiles; iterator++) {
        char name[8] = "input";
        char* tempIter;
        itoa(iterator, tempIter, 10);
        strcat(name, tempIter);
        strcat(name, ".txt");
        FILE *input;
        input = fopen(name, "r");

        struct course[50];
        void readCourses(FILE *input, struct course*){
            char temp[100];
            for (size_t i = 0; i < 50; i++) {
                fgets(temp, 500, input);
                if (temp == "P\n"){
                    return;
                }
                course[i].name = temp[0];
                int j = 1;
                char tempNum[10];
                while (temp[j] != ' ') {
                    strcat(course[i].name, temp[j]);
                    j++;
                }
                while (temp[j] != ' ') {
                    strcat(tempNum, temp[j]);
                    j++;
                }
                course[i].numOfLabs = atoi(tempNum);
                while (temp[j] != '\n') {
                    
                }
            }
        }
    }
    return 0;
}
