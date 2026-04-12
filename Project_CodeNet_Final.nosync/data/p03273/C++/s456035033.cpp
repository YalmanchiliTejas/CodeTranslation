#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

ll mod = 1000000007;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

	ll h, w;
	cin >> h >> w;
	vll okh(h), okw(w);
	vector<string> a(h);	
	REP(i, h){
		cin >> a[i];
		REP(j, w){
			if(a[i][j] == '#'){
				okh[i] = 1;
				okw[j] = 1;
			}
		}
	}
	REP(i, h){
		if(!okh[i]) continue;
		REP(j, w){
			if(okw[j]) cout << a[i][j];
		}
		cout << endl;
	}
    return 0;
}