#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

ll dp[200020][5][2];

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n+1)rep(j,5)rep(k,2) dp[i][j][k]=-inf;
	dp[1][0][1]=a[0];
	dp[2][0][0]=a[1];
	dp[2][0][1]=a[1];
	dp[3][0][0]=a[2];
	FOR(i,1,n)rep(j,5)rep(k,2){
		if(dp[i][j][k]==-inf) continue;
		int now=i/2;
		if(k) now=(i+1)/2;
		FOR(l,2,5){
			int ind=i+l;
			int nk;
			if(ind/2==now+1) nk=0;
			else if((ind+1)/2==now+1) nk=1;
			else continue;
			if(ind<=n){
				chmax(dp[ind][l][nk],dp[i][j][k]+a[ind-1]);
				if(ind%2==0){
					chmax(dp[ind][l][!nk],dp[i][j][k]+a[ind-1]);
				}
			}
			//cout<<i<<' '<<ind<<' '<<nk<<' '<<dp[i][j][k]<<' '<<dp[ind][l][nk]<<endl;
		}
	}
	ll ans=-inf;
	rep(i,n+1){
		if(i/2==n/2){
			rep(j,5) chmax(ans,dp[i][j][0]);
		}
		if((i+1)/2==n/2){
			rep(j,5) chmax(ans,dp[i][j][1]);
		}
	}
	cout<<ans<<endl;
}