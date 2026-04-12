#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	string a,c;
	int n,l,k;
	char m,i;
	stack<char> b[1000];
	cin>>l;
	while(1){
		cin>>a;
		if(a=="push"){
			cin>>n>>m;
			b[n].push(m);}
		else if(a=="pop"){
			cin>>n;
			cout<<b[n].top()<<endl;
			b[n].pop();}
		
		else if(a=="quit"){
			break;}
		else if(a=="move"){
			cin>>n>>k;
			i=b[n].top();
			b[n].pop();
			b[k].push(i);
		}




	}
}