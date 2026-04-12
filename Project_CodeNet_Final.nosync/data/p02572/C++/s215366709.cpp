#include <bits/stdc++.h>
using namespace std;

using ll= long long;
#define double long double
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _set(x) __builtin_popcount(x)
#define _setl(x) __builtin_popcountll(x)
#define PI  3.14159265358979323846264338327950L
#define mod 1000000007LL

void debug(){
	cerr<<"]\n";
}
template<class H,class ... T> void debug(H h,T... t){
	cerr<<h;
	if(sizeof... (t)){
		cerr<<", ";
	}
	debug(t...);
}
#ifdef DEBUG
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)
	#define dpv(...) cerr<< "["#__VA_ARGS__ " : ";for(int i: (__VA_ARGS__)){cerr<<i<<" ";}cerr<<"]\n"
#else
	#define dbg(...) 0
	#define dpv(...) 0
#endif


void solve(){
	int n;
	cin>>n;
	ll s1,s2;
	s1=s2=0;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		s1 = (s1+x)%mod;
		x= (x*x)%mod;
		s2 = (s2+x)%mod;
	}
	s1 = (s1*s1)%mod;
	s1 = (s1-s2+mod)%mod;
	ll half = (mod+1)/2;
	cout<<(s1*half)%mod<<"\n";
}


int32_t main(){
	IOS
	// freopen("input.txt","r",stdin);
	int _;
	// cin>>_;
	_=1;
	for(int i=1;i<=_;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}

/*
   check for overflows int long long
   correct mize of array
*/
