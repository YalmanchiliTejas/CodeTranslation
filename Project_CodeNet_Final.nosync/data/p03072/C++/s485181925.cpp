#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<(ll)n; i++)
#define REPR(i, n) for(ll i=(ll)n-1; i>=0; i--)
#define FOR(i, m, n) for(ll i=(ll)m; i<(ll)n; i++)
#define FORR(i, m, n) for(ll i=(ll)m-1; i>=(ll)n; i--)
#define ALL(x) (x).begin(), (x).end()
#define ASC(v) sort(ALL(v));
#define DESC(v) sort(ALL(v), greater<int>());
#define UNIQ(a) sort(ALL(a));(a).resize(unique(ALL(a)) - a.begin());
#define PRINTD(x, d) cout << fixed << setprecision(d) << x << "\n";
#define DEBUG(x) cout<<#x<<": "<<x<<"\n"
const double PI = acos(-1);
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
bool isprime(int x){ int i; if(x<2)return 0; else if(x==2) return 1; if(x%2==0) return 0; for(i=3; i*i<=x; i+=2) if(x%i==0) return 0; return 1; }
int digsum(int n) { int r=0; while(n>0) { r+=n%10; n/=10; } return r; }
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
void rcmb(ll *x,ll s,ll r,function<void(ll *)>f){if(r==0){f(x);}else{if(s<0)return;rcmb(x,s-1,r,f);x[r-1]=s;rcmb(x,s-1,r-1,f);}}
void cmb(ll n,ll k,function<void(ll *)>f){ll x[k];rcmb(x,n-1,k,f);}
void prm(ll n,function<void(ll *)>f){ll x[n];for(ll i=0;i<n;i++)x[i]=i;do{f(x);}while(next_permutation(x,x+n));}
void prm(ll n,ll k,function<void(ll *)>f){cmb(n,k,[&](ll *c){prm(k,[&](ll *p){ll x[k];for(ll i=0;i<k;i++){x[i]=c[p[i]];}f(x);});});}
// prm(4, 2, [](ll *x){ cout << x[0] << "," << x[1] << "\n"; });


void solve(long long N, std::vector<long long> H){
	ll res = 1;
	FOR(i, 1, N) {
		bool can = true;
		REP(j, i) {
			if (H[j] > H[i]) can = false;
		}
		if (can) res++;
	}
	cout << res << "\n";
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&H[i]);
    }
    solve(N, std::move(H));
    return 0;
}
