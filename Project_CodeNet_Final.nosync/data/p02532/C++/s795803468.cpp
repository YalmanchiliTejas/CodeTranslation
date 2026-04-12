#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int n,p,p1,p2;
	string cmd;
	char bk;

	cin >> n;

	vector<stack<char> > run(n);
	
	while(1){
		cin >> cmd;

		if(cmd == "quit")
			break;
		else if(cmd == "push"){
			cin >> p >> bk;
			run[p - 1].push(bk);
		}
		else if(cmd == "pop"){
			cin >> p;
			cout << run[p - 1].top() << endl;
			run[p - 1].pop();
		}
		else if(cmd == "move"){
			cin >> p1 >> p2;
			run[p2 - 1].push(run[p1 - 1].top());
			run[p1 - 1].pop();
		}
	}
	
	return 0;
}