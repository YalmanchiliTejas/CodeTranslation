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

int main(){
	ll N;
	cin >> N;
	vector<ll> a(N);
	REP(i, N) cin >> a[i];

	ll res = 0;
	while(1){
		bool flag = true;
		REP(i, N){
			if(a[i]>=N){
				flag = false;
				ll tmp = a[i]/N;
				res += tmp;
				a[i] -= tmp*N;
				REP(j, N){
					if(j==i) continue;
					a[j] += tmp;
				}
			}
		}
		if(flag) break;
	}
	cout << res << endl;
    return 0;
}