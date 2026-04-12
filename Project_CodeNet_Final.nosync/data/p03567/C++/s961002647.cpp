#include<bits/stdc++.h>
using namespace std;
int main(){
	string st;
	cin>>st;
	for(register int i=0;i<st.length();++i){
		if(st[i]=='A'&&st[i+1]=='C'){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}