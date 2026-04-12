#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define FOR(i, o, n) for (auto i = (o); (i) < (n); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (auto i = (n)-1; (i) >= 0; --i)
#define REPI(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define REPIR(itr, v) for (auto itr = v.rbegin(); itr != v.rend(); ++itr)
#define fi first
#define se second
#define ll long long
#define V2(name, h, w) vector<vector<int> > name((h), vector<int>(w));
int main(){
	int n; cin >> n;
	if(n==7 or n==5 or n==3) cout << "YES" << endl;
	else cout << "NO" << endl;
}
