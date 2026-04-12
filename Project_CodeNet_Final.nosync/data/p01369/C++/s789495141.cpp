#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define CHMIN(a,b) (a) = min((a),(b))
#define CHMAX(a,b) (a) = max((a),(b))

// left:0 right:1

int main()
{
    char str[35]={};
    int ans;
    int len;
    int act;
    int lr[26]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};
    while(1==1)
    {
        ans=0;
        REP(i,35)str[i]='\0';
        scanf("%s",str);
        if(str[0]=='#')break;
        len=strlen(str);
        act=lr[str[0]-'a'];
        REP(i,len)
        {
            if(lr[str[i]-'a']!=act)
            {
                ans++;
                act=1-act;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
