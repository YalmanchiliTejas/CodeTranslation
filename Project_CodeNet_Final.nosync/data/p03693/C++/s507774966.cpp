#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <tuple>
#include <stack>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(s) cout << s << endl
typedef long long ll;
using namespace std;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main() {
	int a,b,c; cin >> a >> b >> c;
	cout << ((a*100+b*10+c)%4 == 0? "YES": "NO") << endl;
}