#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int a, b, c;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> a >> b >> c;
	if ((a*100+b*10+c) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}