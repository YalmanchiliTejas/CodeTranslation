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
#include <queue>
#include <stack>
#include <map>
using namespace std;
 
#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()
 
#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)
#define dump3(x, y, z) (cout << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", "<< z << ")" << endl)
 
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	vector< stack<string> > vst;
	int n;
	cin >> n;
	vst = vector< stack<string> >(n+1);
	for (;;) {
		string op;
		cin >> op;
		if (op == "quit") break;

		if (op == "push") {
			int i; string operand;
			cin >> i >> operand;
			vst[i].push(operand);
		} else if (op == "pop") {
			int i;
			cin >> i;
			cout << vst[i].top() << endl;
			vst[i].pop();
		} else if (op == "move") {
			int from, to;
			cin >> from >> to;
			vst[to].push(vst[from].top());
			vst[from].pop();
		}
	}
	return 0;
}