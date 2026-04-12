#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	string q;
	vector<stack<char>> v(n);
	while(cin >> q){
		if(q == "push"){
			char c;
			int p;
			cin >> p >> c;
			v[p-1].push(c);
		}
		if(q == "pop"){
			int p;
			cin >> p;
			cout << v[p-1].top() << endl;
			v[p-1].pop();
		}
		if(q == "move"){
			int p1,p2;
			cin >> p1 >> p2;
			v[p2-1].push(v[p1-1].top());
			v[p1-1].pop();
		}
		if(q == "quit") break;
	}
	
	return 0;
}