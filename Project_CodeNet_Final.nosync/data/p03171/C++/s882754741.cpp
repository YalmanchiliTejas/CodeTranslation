#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vector<pii> > vvpii;

#define pb push_back
#define endl '\n'
#define INF (int)1e9
#define EPS 1e-9
#define gcd __gcd
#define rs resize
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; } //for struct sorting

void printV(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}

void print2V(vvi v){
	FOR(i, 0, v.size()){
		FOR(j, 0, v[i].size()){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}


ll n, val[5000], sum, dp[5000][5000];

ll opt(ll i, ll j){
//	cout<< "inside with: " << i << " " << j << endl;
	if(i > j){
//		cout << "invalid indices" << endl;
		return 0;
	}
	if(i == j){
//		cout << "equal indices" << endl;
		return val[i];
	}
	if(dp[i][j] != -1){
//		cout << "already calculated" << endl;
		return dp[i][j];
	}
	dp[i][j] = max( val[i]+min( opt(i+2, j), opt(i+1, j-1) ), val[j]+min( opt(i+1, j-1), opt(i, j-2) ) );
//	cout << "returning: " << dp[i][j] << " for: " << i << " " << j << endl;
	return dp[i][j];	
}

int main(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> val[i];
		sum += val[i];
	}
	ll x = opt(1, n);
//	cout << "ans is: " << x << endl;
	cout << 2*x - sum;
}