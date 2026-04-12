#include<bits/stdc++.h>
#define ll long long
#define dl cout<<"LINE"<<__LINE__<<endl;
#define dbg(x) cout<<#x<<" = "<<x<<endl; 
using namespace std;
int main(){
	int a=0,b=0;
	for(int i=1;i<=3;i++){
		char c;
		cin>>c;
		if(c=='A')a=1;else b=1;
	}
	if(a==b==1)cout<<"Yes"<<endl;else cout<<"No"<<endl;
	return 0;
}