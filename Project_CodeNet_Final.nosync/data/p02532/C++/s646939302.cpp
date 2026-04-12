#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<stack<char> > vec(n);
	string str;
	while(cin >> str, str != "quit")
	{
		if(str == "push")
		{
			int a;
			cin >> a;
			char c;
			cin >> c;
			vec[a - 1].push(c);
		}
		else if(str == "move")
		{
			int a, b;
			cin >> a >> b;
			vec[b - 1].push(vec[a - 1].top());
			vec[a - 1].pop();
		}
		else if(str == "pop")
		{
			int a;
			cin >> a;
			cout << vec[a - 1].top() << endl;
			vec[a - 1].pop();
		}
	}
}

int main()
{
	solve();
	return(0);
}