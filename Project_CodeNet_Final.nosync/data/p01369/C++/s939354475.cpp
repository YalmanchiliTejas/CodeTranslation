#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)

typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	string str;
	string left = "qwertasdfgzxcvb";
	for (;;) {
		cin >> str;
		if (str[0] == '#') break;
		vector<bool> vs;
		rep(i, str.size()) {
			if (left.find(str[i]) != string::npos)
				vs.push_back(true);
			else
				vs.push_back(false);
		}
		int cnt = 0;
		REP(i, 1, vs.size())
			if (vs[i-1] != vs[i])
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}