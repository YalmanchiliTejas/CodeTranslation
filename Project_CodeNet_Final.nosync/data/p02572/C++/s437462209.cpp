#include<bits/stdc++.h>
#define SORT(v) sort(v.rbegin() , v.rend())
#define si(n) scanf( "%d" , &n)
#define sii(n , m) scanf( "%d %d" , &n , &m)
#define sl(n) scanf( "%lld" , &n)
#define sll(n , m) scanf( "%lld %lld" , &n, &m)
#define ss(cad) scanf( "%s" , cad)
#define sz(x) (int)x.size()
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl
#define M 1000000007
#define N_MAX 1000010
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vp;

ll vec[200100];

int main(){
	int n;
	si(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sl(vec[i]);
		vec[i] %= M;
		sum += vec[i];
		sum %= M;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		sum -= vec[i];
		sum = (sum%M+M)%M;
		ans += (vec[i]*sum)%M;
		ans %= M;
	}
	printf("%lld\n", ans);
    return 0;
}