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
	ll H, W;
	cin >> H >> W;
	int a[H][W];
	REP(i, H){
		string S;
		cin >> S;
		REP(j, W){
			a[i][j] = (S[j]=='.'?0:1);
		}
	}
	vector<bool> x(H), y(W);
	REP(i, H){
		ll sum = 0;
		REP(j, W){
			sum += a[i][j];
		}
		x[i] = (sum!=0); 
	}
	REP(j, W){
		ll sum = 0;
		REP(i, H){
			sum += a[i][j];
		}
		y[j] = (sum!=0); 
	}
	REP(i, H){
		if(!x[i]) continue;
		REP(j, W){
			if(!y[j]) continue;
			cout << (a[i][j]==0?'.':'#');
		}
		cout << endl;
	}
    return 0;
}