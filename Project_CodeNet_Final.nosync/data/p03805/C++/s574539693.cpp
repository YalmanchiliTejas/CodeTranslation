#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define allsort(v) sort(v.begin(),v.end())

int main() {
	cin.sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int>v(N);
	rep(i,N)v[i]=i+1;
	int a, b;
	bool path[9][9] = {};
	rep(i, M) {
		cin >> a >> b;
		path[a][b] = path[b][a] = true;
	}
	int ans = 0;
	do {
		if (v[0] != 1)break;
		int k = 0;
		bool flag = true;
		while (k != N - 1) {
			if (!path[v[k]][v[k + 1]]) {
				flag = false;
				break;
			}
			k++;
		}
		if (flag)ans++;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}