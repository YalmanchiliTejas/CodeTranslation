#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
	string s; cin>>s;
	int a=0,b=0;
	if(s[0]=='A'){
		a=1;
	}else{
		b=1;
	}
	if(s[1]=='A'){
		a=1;
	}else{
		b=1;
	}
	if(s[2]=='A'){
		a=1;
	}else{
		b=1;
	}
	if(a*b==0){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	
}
