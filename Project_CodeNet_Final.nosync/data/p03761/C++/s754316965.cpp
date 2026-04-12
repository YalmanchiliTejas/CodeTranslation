#include <stdio.h>
int main(void){
    // Your code here!
    char str[50][26] = {};
    char ch;
    int N;
    
    scanf("%d ",&N);
    
    for(int i = 0; i < N;i ++){
        char tmp[51];
        scanf("%50s",tmp);
        for(int j = 0; tmp[j] != '\0'; j++){
            str[i][tmp[j]-'a']++;
        }
    }
    
    for(int i = 0; i < 26;i++){
        int min = 100;
        for(int j = 0; j < N; j++){
            if(str[j][i] < min){
                min = str[j][i];
            }
        }
        
        for(int j = 0; j < min; j++){
            printf("%c",i + 'a');
        }
    }
}
