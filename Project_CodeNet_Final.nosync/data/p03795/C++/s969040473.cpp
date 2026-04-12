#include <bits/stdc++.h>
using namespace std;

using ll    = long long;
using ull   = unsigned long long;
using veci  = vector<int>;
using vecll = vector<ll>;
#define EPS (1e-7)
#define INF (1e9)
#define PI  (acos(-1))
#define FOR(i,a,b) for(int i = (a);i < (b); ++i)
#define REP(i,n) for(int i= 0;i<(int)(n);++i)
#define pb push_back

veci enum_div(int n){
	veci ret;
	ret.pb(1);
	for(int i=1;i*i<n;i++){
		if(n%i==0){
			ret.pb(i);
			if(i != n/i){ret.pb(n/i);}
		}
	}
	ret.pb(n);
	return ret;
}
int gcb(int a,int b){return ((b == 0)? a : gcb(b,a%b));}
int gcd(int a,int b){return (a*b) / gcb(a,b);}

int main(){
    int n;
    cin >> n;
    ll x = n*800;
    ll y = (n/15)*200;
    cout << x-y << endl;
    return 0;
}

