#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#include <cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
typedef std::pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

const LL M=1e9+7;
const int maxn=2e5+5;
LL A[maxn];

int main()
{
    int n=read();
    REP(i,1,n) A[i]=A[i-1]+read();
    LL ans=0;
    for(int i=1;i<n;i++)
    {
        ans=(ans+(A[n]-A[i])%M*(A[i]-A[i-1]))%M;
    }
    cout<<ans;

    return 0;
}
