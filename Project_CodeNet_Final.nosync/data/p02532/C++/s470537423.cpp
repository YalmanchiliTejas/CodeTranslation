#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

queue<char> gbg;

int main(){
	string act;
	int n,i,j;
	char brk;
	stack<char>* mount;

	cin>>n;
	mount=new stack<char>[n];

	while(1){
		cin>>act;
	if(act=="push"){
		cin>>i>>brk;
		mount[i-1].push(brk);
	}else if(act=="pop"){
		cin>>i;
		gbg.push(mount[i-1].top());
		mount[i-1].pop();
	}else if(act=="move"){
		cin>>i>>j;
		mount[j-1].push(mount[i-1].top());
		mount[i-1].pop();
	}else if(act=="quit"){
		while(gbg.size()){
			cout<<gbg.front()<<endl;
			gbg.pop();
		}
		return 0;
	}
	}
}