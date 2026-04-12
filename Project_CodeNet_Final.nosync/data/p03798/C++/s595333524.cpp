#include<bits/stdc++.h>
using namespace std;
const int pi=3.1415926535897932384626433832795;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
char ch[100005];
char ans[100005];
char tmp;
bool flag;
int n;
int main()
{
    scanf("%d%s",&n,&ch);
    for(int i=0;i<4;i++)
    {
        if(i/2==0)
            ans[0]='S';
        else
            ans[0]='W';
        if(i%2==0)
            ans[1]='S';
        else
            ans[1]='W';
        for(int j=2;j<n;j++)
        {
            tmp=ch[j-1];
            if(ans[j-1]=='W')
                tmp='o'+'x'-tmp;
            if(tmp=='o')
                ans[j]=ans[j-2];
            else
                ans[j]='S'+'W'-ans[j-2];
        }
        if(ans[n-2]==ans[0])
            tmp='o';
        else
            tmp='x';
        if(ans[n-1]=='W')
            tmp='o'+'x'-tmp;
        if(tmp!=ch[n-1])
            continue;
        if(ans[n-1]==ans[1])
            tmp='o';
        else
            tmp='x';
        if(ans[0]=='W')
            tmp='o'+'x'-tmp;
        if(tmp!=ch[0])
            continue;
        flag=1;
        break;
    }
    puts((!flag?"-1":ans));
    return 0;
}