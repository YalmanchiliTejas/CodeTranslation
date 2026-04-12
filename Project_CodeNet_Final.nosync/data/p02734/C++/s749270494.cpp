#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define inf (int)(3e18)
#define mod 998244353

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N,S;
int A[3005],dp[3005];
signed main() {
	cin>>N>>S;
	rep(i,N)cin>>A[i];
	int ans=0;
	rep(i,N){
		for(int j=S;j>=0;j--){
			dp[j]%=mod;
			if(j+A[i]<=S)dp[j+A[i]]+=dp[j];
		}
		dp[A[i]]+=i+1;
		ans+=dp[S];
		ans%=mod;
	}
	cout<<ans<<endl;
}

