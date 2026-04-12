#include <bits/stdc++.h>
using namespace std;
char s[5];
int main(){
    scanf("%s", s+1);    
    int ans = 0;
    for(int i=1;i<=3;i++){
        ans |= (1<<(s[i]-'A'));
    }
    if(ans == 3) printf("Yes\n");
    else printf("No\n");
}