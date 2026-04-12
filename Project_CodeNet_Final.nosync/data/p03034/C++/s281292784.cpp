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
#include <fstream>
#include <time.h>
#include <iterator>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;

int N, s[100010];
signed main() {
	cin >> N;
	REP(i, N) {
		cin >> s[i];
	}
	int ans = 0;
	for (int C = 1; C < N; C++) {
		int res = 0;
		int score = 0;
		set<int>st;
		for (int x = 0; x*C < N-1; x++) {
			//pe(C)pe(x); pe("->");
			int A = N - 1 - x * C;
			int B = A - C;
			if (B <= 0)goto END;
			if (st.find(x*C) != st.end() || st.find(A) != st.end())goto END;
			st.insert(x*C);
			if (st.find(A) != st.end())goto END; 
			st.insert(A);
			score += s[x*C] + s[A];
			res = max(res, score);
			//print(res);
			ans = max(ans, res);
		}
		ans = max(ans, res);
	END:;
		//cout << endl;
	}
	print(ans);
}
