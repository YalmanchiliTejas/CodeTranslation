#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	string s;
	cin>>s; 
	set<char> t; 
	for(auto &it:s)
		t.insert(it); 
	if(t.size()==1)
		cout<<"No"<<endl; 
	else 
		cout<<"Yes"<<endl;
}