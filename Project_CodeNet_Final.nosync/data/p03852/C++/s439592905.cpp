#include <stdio.h>
int main(void){
    // Your code here!
    char c;
    
    scanf("%c",&c);
    
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
        printf("vowel\n");
    }
    else{
        printf("consonant\n");
    }
}
