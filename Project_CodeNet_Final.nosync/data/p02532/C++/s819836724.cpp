#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int n;
	string s;
	int p;
	char c;
	cin >> n;

	vector< stack<char> > yama(n);

	while(1){
		cin >> s;
		if(s == "quit") break;
		else if(s == "push")
		{
			cin >> p >> c;
			yama[p-1].push(c);
		}
		else if(s == "pop")
		{
			cin >> p;
			cout << yama[p-1].top() << endl;
			yama[p-1].pop();
		}
		else
		{
			int p1, p2, k1, k2;
			cin >> p1 >> p2;
			k1 = yama[p1-1].top();
			yama[p1-1].pop();
			yama[p2-1].push(k1);
		}
	}
	return 0;
}