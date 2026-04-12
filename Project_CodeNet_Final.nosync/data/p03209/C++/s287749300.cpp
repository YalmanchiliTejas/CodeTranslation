#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#include<algorithm>
#include<queue>
typedef long long ll;
#include<vector>
#define cin(n) scanf("%lld",&(n))
#define cout(n) printf("%lld",(n))
#define couc(c) printf("%c",(c))
#define coutn printf("\n")
#define cout_ printf(" ")
#define debug() printf("haha\n")
const int MAXN= 1e6 + 5 ;
ll t;
ll n,k;
ll hamburger[MAXN]={1,5};
ll meat[MAXN]={1,3};
ll onemeat[MAXN]={0,0,1,2,3,3};
ll rou=3;
ll now=5;
ll an;
ll findmeat(ll x,ll m)
{
    if(m==1)
        return onemeat[x];
    if(x==1)
        return 0;
    else if(x<hamburger[m]/2+1)
        return findmeat(x-1,m-1);
    else if(x==hamburger[m]/2+1)
        return meat[m-1]+1;
    else if(x>hamburger[m]/2+1&&x!=hamburger[m])
        return meat[m-1]+1+findmeat(x-hamburger[m]/2-1,m-1);
    else if(x==hamburger[m])
        return meat[m];
}
int main()
{
    cin(n);
    cin(k);
    for(int i=2;i<=n;i++)
    {
        meat[i]=meat[i-1]*2+1;
        hamburger[i]=hamburger[i-1]*2+3;
    }
    ll ans=findmeat(k,n);
    cout(ans);
    coutn;
    return 0;
}

