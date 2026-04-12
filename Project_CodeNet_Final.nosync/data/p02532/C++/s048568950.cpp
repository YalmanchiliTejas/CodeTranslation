#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	string str;
	vector<stack<string> > vs(n);
	while (cin >> str, str != "quit") {
		if (str == "pop") {
			cin >> n;
			n--;
			cout << vs[n].top() << endl;
			vs[n].pop();
		} else if (str == "move") {
			cin >> n >> m;
			n--; m--;
			vs[m].push(vs[n].top());
			vs[n].pop();
		} else {
			cin >> n;
			n--;
			cin >> str;
			vs[n].push(str);
		}
	}
	return 0;
}