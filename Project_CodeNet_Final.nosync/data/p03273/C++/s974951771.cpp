#include "bits/stdc++.h"

#define ed cout<<"\n";
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define ffor(i,a,b) for(ll i=(a);i<(ll)(b);++i)
#define rep(i, n) ffor(i,0,n)
#define All(obj) (obj).begin(),(obj).end()
#define EPS (1e-7)
#define INF ((ll)1e9+7)
#define PI (acos(-1))
#define c(a) cout<<a<<"\n";
using namespace std;

int main() {
	speed;
	int h, w;
	char a[101][101];
	cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	vector<bool>hf(h, false);
	vector<bool>wf(w, false);
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] == '#') {
				hf.at(i) = true;
				wf.at(j) = true;
			}
		}
	}
	rep(i, h) {
		if (!hf.at(i))continue;
		rep(j, w) {
			if (!wf.at(j))continue;
			cout << a[i][j];
		}
		ed;
	}
	ed;
	return 0; 
}

