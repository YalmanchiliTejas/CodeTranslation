#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
	char c;
	string str;
	int n,p;
	cin>>n;
	stack<char> color[101];
	while(1){
		cin>>str;
		if(str == "quit") break;
		else if(str == "push"){
			cin>>p>>c;
			color[p].push(c);
		}else if(str == "pop"){
			cin>>p;
			cout<<color[p].top()<<endl;
			color[p].pop();
		}else if(str == "move"){
			int a,b;
			cin>>a>>b;
			char d = color[a].top();
			color[b].push(d);
			color[a].pop();
		}
	}
	return 0;
}