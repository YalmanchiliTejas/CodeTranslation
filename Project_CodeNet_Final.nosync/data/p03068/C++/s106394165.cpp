#include<iostream>
#include<string>
using namespace std;
int main(){
	int a,c;
	string b;
	cin>>a>>b>>c;
	c--;
	for(int i=0;i<a;i++){
		if(b[i]!=b[c])
			b[i]='*';
	}
	cout<<b<<endl;
	return 0;
}