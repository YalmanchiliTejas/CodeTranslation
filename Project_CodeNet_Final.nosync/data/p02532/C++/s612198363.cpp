#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector< stack<char> > m;
	string input;
	int target,to;
	char color;
	cin>>target;
	m.resize(target);
	while(1){
		cin>>input>>target;
		if(input=="push"){
			cin>>color;
			m[target-1].push(color);
		}else if(input=="pop"){
			cout<<m[target-1].top()<<endl;
			m[target-1].pop();
		}else if(input=="move"){
			cin>>to;
			m[to-1].push(m[target-1].top());
			m[target-1].pop();
		}else if(input=="quit")break;
	}
	return 0;
}