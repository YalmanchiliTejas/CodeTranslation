#include <bits/stdc++.h>
using namespace std;

using ll= unsigned long long;
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
	ll n,x,m;
	cin>>n>>x>>m;
	vector<ll> p;
	p.push_back(0);
	map<int,int> t;
	ll last = x;
	ll k=n;
	n--;
	t[last] =1;
	p.push_back(x);
	ll now;
	while(n){
		now= (last*last)%m;
		if(t.count(now)){
			break;
		}
		t[now]=1;
		p.push_back(now);
		last = now;
		n--;
	}
	if(n==0){
		for(int i=1;i<p.size();i++){
				p[i] += p[i-1];
		}
		cout<<p.back()<<"\n";
	}else{
		ll pt;
		n= k;
		bool f=1;
		ll len=(p.size()-1);
		for(int i=1;i<p.size();i++){
			// if(i)cout<<p[i]<<endl;
			if(p[i]==now){ 
				pt= i;
				f=0;
			}
			if(f){
				n--;
				len--;
			}
			p[i] += p[i-1];
		}
		ll ans = p[pt-1]+(n/len)*(p.back()-p[pt-1]) + (p[pt+(n%len)-1]-p[pt-1]);
		cout<<ans<<"\n";
	}
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
