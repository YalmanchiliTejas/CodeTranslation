#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define REP(i,n) FOR(i, 0, n)
#define FORD(i,a,n) for(int i=(a); i>=(n); i--)
#define REPD(i,n) FOR(i, n, 0)

#define ALL(o) (o).begin(), (o).end()

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T, vector<T>, greater<T> >;

const ll MOD = 1000000007;

int main() {
	int n,m;
	cin >> n >> m;

	if(n == m) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}


