#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void){
	int mtn;
	cin >> mtn;

	stack<char> s[101];
	string order;

	while(true){
		cin >> order;
		if(order=="push"){
			int n; char c;
			cin >> n >> c;
			s[n].push(c);
		}
		else if(order=="pop"){
			int n;
			cin >> n;
			cout << s[n].top() << endl;
			s[n].pop();
		}
		else if(order=="move"){
			int i,j;
			cin >> i >> j;
			s[j].push( s[i].top() );
			s[i].pop();
		}
		else break;
	}
	return 0;
}