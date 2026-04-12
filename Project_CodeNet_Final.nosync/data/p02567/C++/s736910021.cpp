//To compile : type "$     g++ test.cpp -std=c++14 -I .    "
#include <atcoder/segtree>
#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
using namespace atcoder;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<60);

ll op(ll a, ll b){ 
	return max(a, b); 
}
ll e(){
	return -1;
}
int target;
bool f(ll v){ 
	return v < target;
}

int main() {
	cin>>N>>Q;
	vec a(N);
	rep(i, N) scanf("%lld", &a[i]);
	segtree<ll, op, e> seg(a);
	int t, x, l, r;
	ll v;
	rep(_, Q){
		scanf("%d", &t);
		if (t == 1) {
            scanf("%d%lld", &x, &v); --x;
            seg.set(x, v);
        } else if (t == 2) {
            scanf("%d%d", &l, &r); --l;
            printf("%lld\n", seg.prod(l, r));
        } else if (t == 3) {
            scanf("%d%d", &x, &target); --x;
			printf("%d\n", seg.max_right<f>(x) + 1);
        }
	}
}
