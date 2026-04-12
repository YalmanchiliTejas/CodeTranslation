#include "bits/stdc++.h"

#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ceel(x, y) (x+y-1)/y
#define print(a) for(auto x:a) cout<<x<<' ';cout<<endl;
#define printM(b) for(auto y:b) {print(y);}
#define printP(p) cout<<p.first<<' '<<p.second<<endl;
#define inp(ar, l, r) for(int i=l ; i<r ; ++i) cin>>ar[i];
#define inpar(ar) for(int i=0 ; i<n ; ++i) cin>>ar[i];
#define debug(ar, n) for(int i=0 ; i<n ; ++i) cout<<ar[i]<<' ';cout<<endl;
#define debugar(ar) for(int i=0 ; i<n ; ++i) cout<<ar[i]<<' ';cout<<endl;
#define qwer cout<<endl;
#define MOD 1000000007

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;

#define pll pair<ll,ll>

const int N = 3001;
ll dp[2][N+1][N+1];
ll ar[N+1], n;

ll calc(int left, int right, bool player, ll score1, ll score2)
{
    if(left > right) return 0;

    if(dp[player][left][right] != -1)
        return dp[player][left][right];
    
    if(player%2 == 0)
    {
        ll temp1 = calc(left+1, right, player^1, score1+ar[left], score2);
        ll temp2 = calc(left, right-1, player^1, score1+ar[right], score2);

        dp[player][left][right] = max(ar[left]+temp1, ar[right]+temp2);
    }
    else
    {
        ll temp1 = calc(left+1, right, player^1, score1, score2+ar[left]);
        ll temp2 = calc(left, right-1, player^1, score1, score2+ar[right]);

        dp[player][left][right] = min(temp1-ar[left], temp2-ar[right]);
    }
    return dp[player][left][right];
}

void solve()
{
    cin>>n;

    for(int i=0 ; i<n ; ++i)
        cin>>ar[i];
    
    memset(dp, -1, sizeof(dp));

    cout<<calc(0, n-1, 0, 0, 0)<<endl;
}

void preCompute() {}

int main()
{
	fastread;

    preCompute();
	
    ll t = 1, tc;
    
    //cin>>t;
    for(tc=1 ; tc<=t ; ++tc) {
        solve();
    }
    
    return 0;
}