#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
	ll n;cin>>n;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];

	if(n==2){
		cout<<max(a[0],a[1])<<endl;
	}

	//nが偶数の時
	if(n%2==0 && n!=2){
		ll dp0[n+10][2],dp1[n+10],which=max(a[n-1],a[n-2]),MAX=-INF;
		rep(i,n+10) dp1[i]=-INF;
		rep(i,n+10) rep(j,2) dp0[i][j]=-INF;

		dp0[0][0]=a[0];
		dp1[1]=a[1];

		//0start
		for(ll i=0;i<n-2;i++){
			for(ll j=0;j<2;j++){
				if(dp0[i][j]==-INF) continue;
				if(i+2<n) chmax(dp0[i+2][j],dp0[i][j]+a[i+2]);
				if(i+3<n && j+1<2) chmax(dp0[i+3][j+1],dp0[i][j]+a[i+3]);
			}
		}
		MAX=max(dp0[n-2][0],dp0[n-1][1]);

		//1start
		for(ll i=1;i<n;i++){
			if(i+2<n){
				if(dp1[i]==-INF) continue;
				chmax(dp1[i+2],dp1[i]+a[i+2]);
			}
		}
		MAX=max(MAX,dp1[n-1]);

		cout<<MAX<<endl;
	}

	//nが奇数の時
	if(n%2==1){
		ll dp0[n+10][3],dp1[n+10][2],dp2[n+10],MAX=-INF;
		rep(i,n+10) rep(j,3) dp0[i][j]=-INF;
		rep(i,n+10) rep(j,2) dp1[i][j]=-INF;
		rep(i,n+10) dp2[i]=-INF;

		dp0[0][0]=a[0];
		dp1[1][0]=a[1];
		dp2[2]=a[2];

		//2start
		for(ll i=2;i<n;i++){
			if(dp2[i]==-INF) continue;
			if(i+2<n) chmax(dp2[i+2],dp2[i]+a[i+2]);
		}
		MAX=max(MAX,dp2[n-1]);
		
		//1start
		for(ll i=1;i<n;i++){
			for(ll j=0;j<2;j++){//j:2個飛ばしを使った回数(1回しか使ってはならない)
				if(dp1[i][j]==-INF) continue;
				if(i+2<n) chmax(dp1[i+2][j],dp1[i][j]+a[i+2]);
				if(i+3<n && j+1<2) chmax(dp1[i+3][j+1],dp1[i][j]+a[i+3]);
			}
		}
		MAX=max(MAX,max(dp1[n-2][0],dp1[n-1][1]));
		
		//0start
		for(ll i=0;i<n;i++){
			for(ll j=0;j<3;j++){//j:2個飛ばしは2回まで、3個飛ばしは1回まで
				if(dp0[i][j]==-INF) continue;
				if(i+2<n) chmax(dp0[i+2][j],dp0[i][j]+a[i+2]);
				if(i+3<n && j+1<3) chmax(dp0[i+3][j+1],dp0[i][j]+a[i+3]);
				if(i+4<n && j+2<3) chmax(dp0[i+4][j+2],dp0[i][j]+a[i+4]);
			}
		}
		MAX=max(MAX,max(dp0[n-3][0],max(dp0[n-2][1],dp0[n-1][2])));
	
		cout<<MAX<<endl;
	}

	return 0;
}