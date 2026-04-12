#include "bits/stdc++.h"
using namespace std;

int main(){
	string t,p;
	cin>>t>>p;
	
	stack<char> st;
	vector<int> b;
	vector<int> f;
	
	for(int i=0;i<p.size();i++)st.push(p[i]);
	
	for(int i=t.size()-1;i>=0;i--){
		if(st.size()&&t[i]==st.top()){
			f.push_back(i);
			st.pop();
		}
	}
	
	if(st.size()){
		cout<<"no"<<endl;
		return 0;
	}
	
	while(st.size())st.pop();
	
	for(int i=p.size()-1;i>=0;i--)st.push(p[i]);
	
	for(int i=0;i<t.size();i++){
		if(st.size()&&t[i]==st.top()){
			b.push_back(i);
			st.pop();
		}
	}
	
	reverse(b.begin(),b.end());
	
	if(b==f&&b.size()==p.size()){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
	
	return 0;
}