#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	string s; cin>>s;
	int a = 0,b = 0;
	for(auto xx : s) { if(xx == 'B') b++; else a++;}
	if(a && b) cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
	
	
	
	
}