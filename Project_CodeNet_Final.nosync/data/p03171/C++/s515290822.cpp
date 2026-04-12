#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fp(i,a,b) for(int i=a ; i<b ; i++)
#define fn(i,a,b) for(int i=a ; i>=b ; i--)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int M=3005;
const ll INF=1e15;
const int MOD=1e9+7;

ll n,sum;
ll a[M],dp[M][M];

ll DP(int i,int j,bool b){
	if (i == j){
		if (b) return a[i];
		else return 0;
	}
	if (dp[i][j] != -1) return dp[i][j];
	if (b) dp[i][j] = max(DP(i+1,j,b^1) + a[i] , DP(i,j-1,b^1) + a[j]);
	else dp[i][j] = min(DP(i+1,j,b^1) , DP(i,j-1,b^1));
	return dp[i][j];
}

int main(){

	fastio;
	cin >> n;
	fp(i,0,n){
		cin >> a[i];
		sum += a[i];
	}
	fp(i,0,n)
		fp(j,0,n) dp[i][j] = -1;
	cout << 2*DP(0,n-1,1) - sum << "\n";

	return 0;
}
