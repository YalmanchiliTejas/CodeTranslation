#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 10002
const ll P = 7+1e9;
string s;
ll n,dp[mx][2][101];

ll fn(ll pos,bool fl,ll rem,ll x = 0){
    if(pos==s.size())   return rem==0;

    ll &ans = dp[pos][fl][rem];
    if(ans!=-1) return ans;
    ans = 0;
    ll lmt = 9;
    if(fl)  lmt = s[pos] - '0';
    for(ll i = 0; i<=lmt; i++){
        bool F = fl;
        if(i<lmt)   F = false;
        ans = (ans+fn(pos+1,F,(rem+i)%n,x*10+i))%P;
    }
    return ans;
}

main(){
int t,tc = 0;

memset(dp,-1,sizeof dp);
cin>>s>>n;
ll ans = fn(0,1,0) - 1;
printf("%lld\n",(ans+P)%P);

return 0;
}

