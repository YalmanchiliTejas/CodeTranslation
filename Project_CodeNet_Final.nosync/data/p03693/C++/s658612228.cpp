#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SORT(i) sort((i).begin(),(i).end())
constexpr int INF = 2000000000;
constexpr int mod = 1000000007;

int main() {
	char ch[3];
	rep(i, 3)cin >> ch[i];
	string s(ch, 3);
	cout << (stoi(s) % 4 == 0 ? "YES" : "NO") << "\n";

	return 0;
}