#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n, k, t;
	cin >> n;
	vector<stack<char> > vst(n + 1);
	char c;
	string s;
	while (cin >> s)
	{
		if (s == "quit") break;
		else if (s == "push"){
			cin >> k >> c;
			vst[k].push(c);
		}else if (s == "pop"){
			cin >> k;
			cout << vst[k].top() << "\n";
			vst[k].pop();
		}else if (s == "move"){
			cin >> k >> t;
			c = vst[k].top();
			vst[k].pop();
			vst[t].push(c);
		}
	}
	return 0;
}