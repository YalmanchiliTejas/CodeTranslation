#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char str[10];

int main(){
    scanf("%s",str);
    for(int i=1;i<strlen(str);i++){
        if(str[i]=='C' && str[i-1]=='A'){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
