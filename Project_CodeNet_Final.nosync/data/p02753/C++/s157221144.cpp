#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	set<char> set;
	for(int i=0;i<s.size();i++){
		set.insert(s[i]);
	}
	
	if(set.size()==2){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}