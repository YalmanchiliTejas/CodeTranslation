#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	bool f = false;
	if(s[0] == 'A') f = true;
	for(int i=1;i<s.size();i++){
		if(s[i] == 'C' && f){
			cout<<"Yes"<<endl;
			return 0;
		}
		else if(s[i] == 'A'){
			f = true;
		}
		else{
			f = false;
		}
	}
	cout<<"No"<<endl;
}