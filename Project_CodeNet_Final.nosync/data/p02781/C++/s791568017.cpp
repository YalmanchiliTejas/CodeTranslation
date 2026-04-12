/// Updated! https://www.youtube.com/watch?v=U07_n9xGIlM
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define dbug printf("I am here\n");
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int maxn = 2e5+100;

const ll inf = 1e18;

string s;
int k;
ll dp[200][20][2][2];

ll solve(int i , int p , bool boro, bool st){
    if(i == s.size() and p==0)return 1ll;
    if(i == s.size())return 0;
    if( p < 0 )return 0;
    ll &ret = dp[i][p][boro][st];
    if(ret != -1)return ret;
    ll mx = s[i]-'0';
    if(boro == false)mx = 9;
    ret = 0;
    for(int d = 0; d<=mx; d++){
        ret += solve(i+1,p-(d!=0), boro&(d==mx) , st|d>0);
    }
    return ret;
}

int main()
{
    fast;
    cin >> s >> k;
    memset(dp,-1,sizeof dp);
    cout << solve(0,k,true,false) << endl;
    return 0;
}
/*



*/

