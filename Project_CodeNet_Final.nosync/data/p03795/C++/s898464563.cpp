#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SORT(i) sort((i).begin(),(i).end())
constexpr int INF = 2000000000;
constexpr int mod = 1000000007;

int main() {
	int N; cin >> N;
	int ans = 800 * N - 200 * (N / 15);
	cout << ans << "\n";
	return 0;
}