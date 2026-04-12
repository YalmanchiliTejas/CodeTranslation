#include<iostream>
using namespace std;
int main(){
	string c;
	cin>>c;
	int f=0,t=0;
	for(int i=0;i<c.size();i++) f|=c[i]=='B',t|=c[i]=='A';
	if(!f||!t) cout<<"No";
	else cout<<"Yes";
	return 0;
}
