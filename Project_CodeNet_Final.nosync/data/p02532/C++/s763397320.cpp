#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(void){

	int n;
	string text;
	cin>>n;
	vector <stack <string> > buf(n);

	while (true){
		cin>>text;
		if (text == "quit")
			break;
		else if (text == "push"){
			int n;
			cin>>n;
			string c;
			cin >> c;
			buf[n-1].push(c);
		}
		else if (text == "pop"){
			int n; 	cin>>n;
			string c; c = buf[n-1].top();
			buf[n-1].pop();
			cout<<c<<endl;
		}
		else if (text == "move"){
			int n1, n2; cin>>n1; cin>>n2;
			string c; c = buf[n1-1].top();
			buf[n1-1].pop();
			buf[n2-1].push(c);
		}
	}

	return 0;
} 