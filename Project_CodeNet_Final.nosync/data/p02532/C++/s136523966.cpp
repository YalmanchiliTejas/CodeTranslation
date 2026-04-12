#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int n;
	scanf("%d", &n);
	stack<char> stin[200];
	
	while (cin >> str, str != "quit"){
		if (str == "push"){
			char c;
			int x;
			scanf("%d", &x);
			scanf(" %c", &c);
			
			stin[x].push(c);
		}
		else if (str =="pop"){
			int x;
			scanf("%d", &x);
			cout << stin[x].top() <<endl;
			stin[x].pop();
		}
		else if (str == "move"){
			int x1, x2;
			scanf("%d %d", &x1, &x2);
			stin[x2].push(stin[x1].top());
			stin[x1].pop();
		}
	}
}