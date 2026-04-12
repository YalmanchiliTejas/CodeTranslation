#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[4];
    scanf("%s",s);
    if(s[0]!=s[1]){
        printf("Yes");
    }else if(s[1]!=s[2]){
        printf("Yes");
    }else if(s[0]!=s[2]){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}