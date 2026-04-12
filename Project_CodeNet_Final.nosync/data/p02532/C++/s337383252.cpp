#include <iostream>
#include <stack>

using namespace std;

stack<char> S[101];

int main()
{	
	string str;
	int n;
	
	cin >> n;
	while (cin >> str, str != "quit"){
		char c;
		cin >> n;
		if (str[2] == 's'){
			cin >> c;
			S[n - 1].push(c);
		}
		else if (str[0] == 'm'){
			int m;
			cin >> m;
			S[m - 1].push(S[n - 1].top());
			S[n - 1].pop();
		}	
		else {
			cout << S[n - 1].top() << endl;
			S[n - 1].pop();
		}
	}
	return (0);
}