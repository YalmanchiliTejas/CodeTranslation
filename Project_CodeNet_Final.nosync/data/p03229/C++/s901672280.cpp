#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

int a[N];
int b[N];
int c[N];

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n);
	deque<int> d;
	int fr = 0, bk = n-1;
	d.pf(a[fr++]);
	while(1){
		if(fr > bk) break;
		d.pf(a[bk--]);
		if(fr > bk) break;
		d.pb(a[bk--]);
		if(fr > bk) break;
		d.pf(a[fr++]);
		if(fr > bk) break;
		d.pb(a[fr++]);
	}
	rep(i,0,n) b[i] = d.front(),d.ppf();
	
	fr = 0, bk = n-1;
	d.pf(a[bk--]);
	while(1){
		if(fr > bk) break;
		d.pf(a[fr++]);
		if(fr > bk) break;
		d.pb(a[fr++]);
		if(fr > bk) break;
		d.pf(a[bk--]);
		if(fr > bk) break;
		d.pb(a[bk--]);
	}
	rep(i,0,n) c[i] = d.front(),d.ppf();
	
	int ans1 = 0;
	rep(i,1,n){
		ans1 += abs(b[i] - b[i-1]);
	}
	
	int ans2 = 0;
	rep(i,1,n){
		ans2 += abs(c[i] - c[i-1]);
	}
	
	cout<<max(ans1,ans2);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
