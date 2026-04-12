#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void){
    char s[3]; 
    int yes = 1;

    scanf("%s", s);
    yes = 1;
//    printf("%s %c %c %c %d\n", s, s[0], s[1], s[2], yes);

    if(s[0] == s[1] && s[0] == s[2]){
        yes = 0;
//        printf("aaa\n");
    }
//    printf("%s %c %c %c %d\n", s, s[0], s[1], s[2], yes);

//    yes = 1;
    if(yes == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;

} 
