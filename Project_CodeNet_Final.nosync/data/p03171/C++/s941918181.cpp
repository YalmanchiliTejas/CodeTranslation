#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()

const int MOD = 1000000007;
const int N = 3005;
const double PI =4*atan(1);

ll dp[N][N];
ll n;
ll a[N];

ll dfs(ll l ,ll r){
	if(l>r)return 0;
	if(dp[l][r]>-1e17)return dp[l][r];
	ll to_return = -1e17;
	to_return =max(to_return , a[r]-dfs(l,r-1));
	to_return =max(to_return , a[l]-dfs(l+1,r));
	return dp[l][r]=to_return;
}

int main(){
    ios::sync_with_stdio(0);
    //freopen("baklava.in","r",stdin);
    cin.tie(0);
    cout.tie(0);
    //start
    cin >> n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		dp[i][j]=-1e17;
    	}
    }
    for(int i=0;i<n;i++)cin >> a[i];
    ll ans=dfs(0,n-1);
    cout << ans;

    return 0;
}
