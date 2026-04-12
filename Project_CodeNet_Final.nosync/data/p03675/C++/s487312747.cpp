#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = n;i >= m;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 5999999999999999999
#define ALL(n) n.begin(),n.end()
#define ABS(a,b) max(a,b) - min(a,b)

vector<int> s;

int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		s.push_back(a);
	}
	if (n % 2 == 1) {
		for (int i = n - 1; i >= 0; i -= 2) cout << s[i] << " ";
		for (int i = 1; i < n - 2; i += 2) cout << s[i] << " ";
		if(n > 2)cout << s[n - 2] << endl;
	}
	else {
		for (int i = n - 1; i > 0; i -= 2) cout << s[i] << " ";
		for (int i = 0; i < n - 2; i += 2) cout << s[i] << " ";
		if (n > 1)cout << s[n - 2] << endl;
	}
}