#include<bits/stdc++.h>
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
 
template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr long long inf = 3e18;

int N,X,M;
int sum[100005];
int used[100005];
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	memset(used,-1,sizeof(used));
	cin>>N>>X>>M;
	rep(i,N){
		if(used[X]!=-1){
			int ans=sum[used[X]];
			ans+=(sum[i]-sum[used[X]])*((N-used[X])/(i-used[X]));
			ans+=sum[used[X]+(N-used[X])%(i-used[X])]-sum[used[X]];
			cout<<ans<<"\n";
			return 0;
		}else if(!X){
			cout<<sum[i]<<"\n";return 0;
		}
		else {
			sum[i+1]=sum[i]+X;
			used[X]=i;
			(X*=X)%=M;
		}
	}
	cout<<sum[N]<<"\n";
}