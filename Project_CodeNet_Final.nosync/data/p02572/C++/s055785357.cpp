#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define speedX ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T>
void __f(const char* s, T t) { cout << s << " : "; __p(t); }
template<typename T>
void __t(const char* s, const T &x) { cout << s << " : { "; for (auto it : x) __p(it); cout << "} ";}
template<typename T, typename ... F>
void __f(const char* s, T t, F ... f) {
	int i = 0; for (;; ++i) if (s[i] == ',') break;
	cout.write(s, i) << " : "; __p(t); cout << " | "; __f(s + i + 1, f...);
}
#define trace(...) { cout<<"LINE: "<<__LINE__<<" || "; __f(#__VA_ARGS__,__VA_ARGS__); cout<<"\n\n"; }
#define debug(...) { cout<<"LINE: "<<__LINE__<<" || "; __t(#__VA_ARGS__,__VA_ARGS__); cout<<"\n\n"; }
int begtime = clock();
#define end_time() cout << "\n\nTime of execution: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define trace(...)
#define debug(...) 
#define end_time()
#endif
 
 
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

inline bool equals(ld a, ld b) {return fabs(a - b) < 1e-9;}
inline int gcd(int a, int b) { a=abs(a); b=abs(b); while(a>0 && b>0) (a>b?a%=b:b%=a); return (a==0?b:a); } 
inline int power(int x, int n, int m = LLONG_MAX)
    {  int res=1; x = (x%m + m)%m;
       while(n) { if(n&1) res=(res*x)%m;  x=(x*x)%m;  n >>= 1; }  return res;
    }
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define mod 1000000007

void solve(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int pre[n] = {0};
	int sum = 0;
	for(int i = 0; i<n; i++){
		sum+=a[i];
		pre[i] = sum%mod;
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		ans = (ans + ((a[i]*((pre[n-1]-pre[i]+mod)%mod))%mod))%mod;
	}
	cout<<ans<<"\n";
}
signed main(){
	speedX;
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	int t=1;
	//cin>>t;
	for(int i=1;i<=t;++i) {
		//cout<<"Case #"<<i<<": ";
		solve();
	}
	end_time();
	return 0;
}
