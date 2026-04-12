#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#ifdef LOCAL
#define debug(x) cerr << '[' << #x << " = " << (x) << "]\n"
#else
#define debug(x)
#endif
const int maxn=3000;
ll dp[maxn][maxn],v[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	rep(i,0,n)cin>>v[i];
	per(i,0,n){
		rep(j,i,n){
			if(i==j){
				dp[i][j]=v[i];
			}else{
				dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<'\n';
}