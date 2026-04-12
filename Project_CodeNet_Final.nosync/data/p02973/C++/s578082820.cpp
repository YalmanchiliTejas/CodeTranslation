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

// 最長増加部分列の長さを求める
int LIS(const vector<long long> &a) {
	int N = (int)a.size();
	vector<long long> dp(N, INF);
	for (int i = 0; i < N; ++i) {
		// dp[k] >= a[i] となる最小のイテレータを見つける
		auto it = upper_bound(dp.begin(), dp.end(), a[i]);

		// そこを a[i] で書き換える
		*it = a[i];
	}

	// dp[k] < INF となる最大の k に対して k+1 が答え
	// それは dp[k] >= INF となる最小の k に一致する
	return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n){
		cin>>a[i];
		a[i]*=-1;
	}
	cout<<LIS(a)<<endl;
}