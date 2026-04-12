#include <bits/stdc++.h>
using namespace std;

char s[99];

int main(){
    scanf("%s", s);
    int N = strlen(s);
    for(int i = 0; i < N - 1; ++i){
        if(s[i] == 'A' && s[i + 1] == 'C')return 0 & puts("Yes");
    }
    puts("No");
    return 0;
}
