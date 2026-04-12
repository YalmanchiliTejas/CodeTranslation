#include <stdio.h>
int main(void){
    // Your code here!
    char s[4];
    
    scanf("%s", s);
    if(s[0]==s[1] && s[1]==s[2]) printf("No");
    else printf("Yes");
}
