#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

stack<char> st[200];
queue<char> ans;

int main(){
	string str;
	char c;
	int a,b;
	cin >> a;
	while(cin >> str){
		if(str == "quit")
			break;
		else if(str == "push"){
			cin >> a >> c;
			a--;
			st[a].push(c);
		}
		else if(str == "pop"){
			cin >> a;
			a--;
			ans.push(st[a].top());
			st[a].pop();
		}
		else{
			cin >> a >> b;
			a--;b--;
			st[b].push(st[a].top());
			st[a].pop();
		}
	}
	while(!ans.empty()){
		cout << ans.front() << endl;
		ans.pop();
	}
	return 0;
}