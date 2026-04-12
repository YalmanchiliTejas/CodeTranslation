#include<stdio.h>
int main(){
    char c;
    while(~scanf("%c",&c)){
        getchar();
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            printf("vowel\n");
            //printf("Since %c is a vowel, print vowel.\n",c);
        }
        else{
            printf("consonant\n");
        }
    }
    return 0;
}
