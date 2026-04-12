#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

ll beki(ll x, ll y){
	if(y==0) return 1;
	return x*beki(x, y-1);
}

ll rec(ll n, ll x){
	ll bek = beki(2, n+1);
	ll res;
	if(n==0 && x==1) res = 1;
	else if(x==1) res = 0;
	else if(x>1 && x<=1+(bek-3)) res = rec(n-1, x-1);
	else if(x==1+(bek-3)+1) res = beki(2, n);
	else if(x>1+(bek-3)+1 && x<=(2*(bek-3)+2)) res = (beki(2, n) + rec(n-1, x-bek+1));
	else if(x==2*(bek-3)+3) res =  2*(beki(2, n) - 1)+1;
	return res;
}

int main(){
	ll N, X;
	cin >> N >> X;
	cout << rec(N, X) << endl;
    return 0;
}