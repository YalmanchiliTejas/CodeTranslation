#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define enld endl

int main() {
	int N, M;
	cin >> N >> M;
	vector<set<int>>G(N);
	int a, b;
	rep(i, M) {
		cin >> a >> b;
		a--; b--;
		G[a].insert(b);
		G[b].insert(a);
	}

	bool ok = true;

	vector<int> v;
	rep(i, N) {
		v.push_back(i);
	}
	int ans = 0;
	do {
		if (v[0] == 0) {
			ok = true;
			rep(i, N - 1) {
				if (G[v[i]].count(v[i + 1])) {

				}
				else {
					ok = false;
				}
			}
			if (ok) {
				ans++;
			}
			ok = true;
		}
		

		

	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}