#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main(void)
{	
	stack<string> st[100];
	queue<string> q;
	int q_index = 0,num,p1,p2;
	string mes;

	string ch;

	cin >> num;

	for (;;)
	{
		cin >> mes;

		if (mes == "push")
		{
			cin >> num;
			cin >> ch;
			st[num].push(ch);

		}

		else if (mes == "move")
			

		{
			cin >> p1;
			cin >> p2;
			st[p2].push(st[p1].top());
			st[p1].pop();

		}

		else if (mes == "pop")
		{
			cin >> num;

			q.push(st[num].top());
			st[num].pop();
			q_index++;

		}
		else if (mes == "quit")
		{
			break;

		}
	}


	for (int i = 0; i < q_index; i++)
	{
		cout << q.front() << endl;
		q.pop();
	}




	
}