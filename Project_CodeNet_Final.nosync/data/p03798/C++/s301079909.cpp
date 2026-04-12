// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
char p[101000];
int S[101000],P[101000],n;
int main() {
    scanf("%d",&n);
    scanf("%s",p);
    int i,j;
    for(int i=0;p[i];i++) {
        if(p[i]=='o') P[i+1]=0;
        else P[i+1]=1;
    }
    P[n+1]=P[1];
    for(int i=0;i<8;i++) {
        S[0]=i&1;
        S[1]=(i>>1)&1;
        S[2]=(i>>2)&2;
        for(int j=2;j<=n+1;j++) {
            S[j+1]=S[j-2]^P[j];
        }
        if(S[0]^S[n]^S[1]^S[n+1] || S[1]^S[n+1]^S[2]^S[n+2]) continue ;
        for(int j=1;j<=n;j++) {
            printf("%c",(S[j]^S[j-1])?'W':'S');
        }
        cout<<endl;
 //       system("pause");
        return 0;
    }
    cout<<-1<<endl;
 //   system("pause");
}