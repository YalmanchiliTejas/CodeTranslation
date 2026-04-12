#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map<pii, int> mp;
	rep(i, n){
		rep(j, n){
			mp[(pii){i, j}] = 0;
			mp[(pii){j, i}] = 0;
		}
	}

	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		mp[(pii){a, b}] = 1;
		mp[(pii){b, a}] = 1;
	}

	vector<int> v;
	rep(i, n) v.push_back(i);

	ll ans = 0;
	do{
		if(v[0] != 0) continue;

		bool ok = true;
		for(int i = 0; i < n-1; i++){
			if(!mp[(pii){v[i], v[i+1]}]){
				ok = false;
				break;
			}
		}
		if(ok) ans++;
	}while(next_permutation(v.begin(), v.end()));

	cout << ans << endl;

}
