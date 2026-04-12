//http://lightoj.com/volume_showproblem.php?problem=1068

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

const LL MOD=1e9+7;
int k;
string str;
LL dp[10005][105][2];

LL call(int pos,int isSmall,int rem)
{
    if(pos==str.size()) {
        if(rem==0) return 1;
        else return 0;
    }
    if(dp[pos][rem][isSmall]!=-1) return dp[pos][rem][isSmall];
    int last=9;
    if(!isSmall) last=str[pos]-'0';
    LL ret=0;
    for(int i=0;i<last;i++) ret=(ret+call(pos+1,1,(rem+i)%k))%MOD;
    if(!isSmall) ret=(ret+call(pos+1,0,(rem+last)%k))%MOD;
    else ret=(ret+call(pos+1,1,(rem+last)%k))%MOD;
    return dp[pos][rem][isSmall]=ret;
}

int main()
{
    Fast
    cin >> str >> k;
    MEM(dp,-1);
    cout << (call(0,0,0)-1+MOD)%MOD;
}
