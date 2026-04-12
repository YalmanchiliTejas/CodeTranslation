/******************************************
* AUTHOR : SHUBHAM KUMAR *
* NICK : { "CODECHEF" : "SCHELEON",
           "CODEFORCES" : "SCH3130N" } *     
* INSTITUTION : BIT MESRA *
******************************************/

#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sd(x) scanf("%lld",&x)
#define pds(x) printf("%lld ", x)
#define large 100005
#define MOD 1000000007
#define dd double
#define pb push_back
#define mk make_pair
#define rep0(i,b) for(int i=0;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define pll pair<ll, ll>
#define ld long double
#define vll vector<ll>
#define vpll vector<pll>
#define sortv(v) sort(v.begin(),v.end())  

template <typename T> void max_self(T& a, T b) {
    a = max(a, b);
}

using ll = long long int;
using ull = unsigned long long int;

ll ModE(ll x, ull y, ll p = MOD) 
{ 
    ll res = 1;
    x = x % p;    
    while (y > 0) 
    {   if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
}
ll a[large];
ll dp[3001][3001][2];
ll solve(ll i, ll j, ll turn){
	if(i == j){
		if(turn%2)
			return a[i];
		else
			return -a[i];
	}

	if(dp[i][j][turn] != -1)
		return dp[i][j][turn];

	if(turn%2){
		dp[i][j][turn] = max(a[i] + solve(i+1, j, turn^1), a[j] + solve(i, j-1, turn^1));
		return dp[i][j][turn];
	} else {
		dp[i][j][turn] = min(-a[i] + solve(i+1, j, turn^1), -a[j] + solve(i, j-1, turn^1));
		return dp[i][j][turn];
	}
}

int main() {
    #ifdef M_DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fastio

    // ll T; cin>>T; while(T--){}
    ll n;
    cin>>n;
    rep0(i, 3001)
    	rep0(j, 3001)
    		rep0(k, 2)
    			dp[i][j][k]=-1;
    rep0(i, n)
    	cin>>a[i];
    cout<<solve(0, n-1, 1);

    return 0;
}