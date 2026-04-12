#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<string> s[101];
	while(true)
	{
		string f;
		cin >> f;
		if(f == "quit")
			break;
		else if(f == "push")
		{
			int m;
			cin >> m;
			string c;
			cin >> c;

			s[m].push(c);
		}
		else if(f == "pop")
		{
			int m;
			cin >> m;
			cout << s[m].top() << endl;
			s[m].pop();
		}
		else if(f == "move")
		{
			int m1, m2;
			cin >> m1 >> m2;
			s[m2].push(s[m1].top());
			s[m1].pop();
		}
	}
	return 0;
}