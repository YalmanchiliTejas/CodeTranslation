#include <bits/stdc++.h>
using namespace std;

int n;
char s[111];
int Min[666];
int Now[666];

int main(){
    memset(Min, 0x3f, sizeof(Min));
    scanf("%d", &n);
    while(n--){
        memset(Now, 0, sizeof(Now));
        scanf("%s", s + 1);
        int Length = strlen(s + 1);
        for(int i = 1; i <= Length; i++) Now[s[i]]++;
        for(int i = 'a'; i <= 'z'; i++) Min[i] = min(Min[i], Now[i]);
    }
    for(int i = 'a'; i <= 'z'; i++){
        for(int k = 1; k <= Min[i]; k++){
            printf("%c",(char)i);
        }
    }
    return 0;
}

