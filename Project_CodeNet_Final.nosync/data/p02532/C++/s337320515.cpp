#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> st[n];

	string com;
	while(cin>>com){
		if(com=="quit") break;
		else if(com=="push"){
			int n;
			char ch;
			cin >> n >> ch;
			st[n-1].push(ch);
		}
		else if(com=="pop"){
			int n;
			cin >> n;
			char ch = st[n-1].top();
			cout << ch << endl;
			st[n-1].pop();
		}else if(com=="move"){
			int p1, p2;
			cin >> p1 >> p2;
			char ch = st[p1-1].top();
			st[p1-1].pop();
			st[p2-1].push(ch);
		}
	}

	return 0;
}

		  