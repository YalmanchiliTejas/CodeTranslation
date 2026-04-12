#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    char s[4];
    scanf("%s",s);
    if(s[1] == s[2] && s[2] == s[0])
        printf("No\n");
    else
        printf("Yes\n");
}
