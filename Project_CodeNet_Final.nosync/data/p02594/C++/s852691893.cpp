#include "bits/stdc++.h" // 提出時こちらで問題なし
//#include <iostream>
//#include <string>
//#include <typeinfo>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define REP2(i, s, n) for (int i=(int)(s); i<(int)(n); i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
#define SORT(c) sort((c).begin(),(c).end())
#define R_SORT(c) sort((c).begin(),(c).end(),greater<>())
using G = vector<vector<int>>;
using M = map<int, int>;
using P = pair<int, int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

// A - Air Conditioner
int main() {
	int x;
	cin >> x;
	if (x >= 30) {
		cout << "Yes" endl;
	}
	else {
		cout << "No" endl;
	}


	return 0;
}