#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string str;
	cin>>str;
	int f1=0,f2=0;
	for(int i=0;i<3;i++){
		if(str[i]=='A')f1=1;
		if(str[i]=='B')f2=1;
	}
	if(f1 && f2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}