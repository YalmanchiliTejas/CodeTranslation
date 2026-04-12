#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

template<class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		return true;
	}
	return false;
}

int main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int m=1<<n;
	int p[m];
	for(i=0;i<m;i++) {
		cin>>p[i];
		p[i]--;
	}
	VVI dp(n+1,VI(m));
	for(i=0;i<m;i++) dp[0][i]=p[i];
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++){
			int x=dp[i-1][j];
			int y=dp[i-1][(j+(1<<(i-1)))%m];
			if(x>y) swap(x,y);
			if(s[y-x-1]=='0') dp[i][j]=x;
			else dp[i][j]=y;
		}
	}
	for(i=0;i<m;i++){
		cout<<dp[n][i]+1<<endl;
	}


}
