#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
	int p,n,n2;
	cin>>p;
	stack<char>* s;
	s = new stack<char>[p];
	string str;
	char ch;
	while(1){
		cin>>str;
		if(str.compare("quit")==0)break;	
		else if(str=="pop"){
			cin>>n;
			cout<<s[n-1].top()<<endl;
			s[n-1].pop();
		}
		else if(str=="push"){
			cin>>n>>ch;
			s[n-1].push(ch);
		}
		else if(str=="move"){
			cin>>n>>n2;
			s[n2-1].push(s[n-1].top());
			s[n-1].pop();
		}
	}
	return 0;
}