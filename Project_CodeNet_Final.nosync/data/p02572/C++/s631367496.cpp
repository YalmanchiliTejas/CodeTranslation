#include<bits/stdc++.h>
using namespace std;


#define ALL(a) 		(a.begin() , a.end())
#define ll 			long long int
#define ff          first
#define ss          second
#define pb          push_back
#define ar 			array
#define mp 			make_pair
#define f(i,a,b)   	for(ll i =a;i<=b;i++)
#define inf 		INT_MAX
#define pll 		pair<ll,ll>
#define mat 		vector<vector<ll>>

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 //debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }
 

const ll INF = 1e18;
void init(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
}
 
bool checkp2(ll n){
	return n && !(n & (n-1));
}

ll numsetbit(ll n){
	ll count = 0;
	for(;n;count++){
		n = n & (n-1);
	}
	return count;
}
 
ll power(ll x , ll n , ll mod){
    x = x % mod;
	ll po = 1;
	while(n){
		if(n & 1){
			po = (po*x) % mod;
		}
		n = n>>1;
		x = ((x % mod) * (x % mod)) % mod;
	}
	return po;
}
 
bool isPrime(ll x){
	if(x < 2)
		return 0;
	for(ll y = 2; y * y <= x; y++){
		if(x % y == 0){
			return 0;
		}
	}
	return true;
}



const ll mod = 1e9 + 7;



void solve(){

		ll n;
		cin>>n;
		vector<ll> a(n+10 , 0);
		ll sum = 0;
		for(ll i = 0;i<n;i++){
			cin>>a[i];
			if(i)
				sum+=a[i];

			sum %= mod;
		}

		ll answer = 0;

		for(ll i = 0;i<n;i++){

			answer += sum * a[i];
			answer %= mod;

			sum -= a[i+1];
			sum %= mod;
			sum += mod;
			sum %= mod;
		}
		cout<<answer<<endl;


}

int main(){
	
	init();
	ll t = 1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}