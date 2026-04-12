#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	int a=0,b=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s.substr(i,1)=="A"){
			a++;
		}else{
			b++;
		}
	}
	if(a==3||b==3){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}

}
