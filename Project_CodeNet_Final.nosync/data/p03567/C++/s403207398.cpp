#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=800+10,M=1500,INF=0x3f3f3f3f;
int main()
{
    int n,m,a,b,c;
    char s[N];
    while(~scanf("%s",s)){
        bool flag=0;
        for(int i=0;i<strlen(s);i++){
            if((s[i]=='a'||s[i]=='A')&&(s[i+1]=='c'||s[i+1]=='C')){
                flag=1;break;
            }

        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
 }
