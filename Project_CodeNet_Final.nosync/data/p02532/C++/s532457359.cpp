#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
#include <cctype>

using namespace std;

int main()
{
	string str;
	int num, m, n;
	char color;

	cin >> num;
	vector< stack<char> > S(num);

	while(true) {
		cin >> str;
		if(str == "quit")
			break;
		if(str == "push") {
			cin >> m >> color;
			S[m - 1].push(color);
		}
		else if (str == "move") {
			cin >> m >> n;
			S[n - 1].push(S[m - 1].top());
			S[m - 1].pop();
		}
		else {
			cin >> m;
			cout << S[m - 1].top() << endl;
			S[m - 1].pop();
		}
	}
	return 0;
}