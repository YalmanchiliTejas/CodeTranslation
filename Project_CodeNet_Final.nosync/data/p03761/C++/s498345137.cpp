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

#define INF LLONG_MAX / 5
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define enld endl


signed main() {
	int N;
	cin >> N;
	vector<string>S(N);
	rep(i, N) {
		cin >> S[i];
	}
	vector < vector<int>>AL(N, vector<int>(26));
	rep(i, N) {
		rep(j, S[i].size()) {
			AL[i][S[i][j] - 'a']++;
		}
	}
	
	vector<int>NUM(26);
	rep(j, 26) {
		int m = INF;
		rep(i, N) {
			m = min(m, AL[i][j]);
		}
		rep(_, m) {
			cout << char('a' + j);
		}
	}
	cout << endl;
}