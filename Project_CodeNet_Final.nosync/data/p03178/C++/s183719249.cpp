#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 1e9 + 7 ;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX =  1e4 + 10 ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m , x ,y, k , d , Q , ans ; string s,t;
ll dp[2][101][MAX];
int K[MAX];

ll solve(int i , int cur , bool tooksmaller){

   
    if(i == n)
        return cur == 0;

    ll &ret = dp[tooksmaller][cur][i];
    if(~ret)
        return ret;

    int sz = (tooksmaller? 9 : K[i]);

    ret = 0 ;

    for(int j = 0 ; j <= sz ; ++j)
        ret = (ret%MOD + solve(i + 1,(cur + j)%d,tooksmaller || (j < K[i]))%MOD)%MOD;

    return ret;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
//   freopen("test.in","r",stdin);


    cin>>s>>d;

    n = (int)s.length();

    for(int i = 0 ; i < n ; ++i)
        K[i] = s[i] - '0';

    for(int i = 0 ; i < d; ++i)
        for(int j = 0 ; j < n ; ++j)
            for(int k = 0 ; k < 2 ; ++k)
                dp[k][i][j] = -1;

    cout<<(solve(0,0,0) - 1 + MOD)%MOD<<'\n';

  

    return 0;
}
