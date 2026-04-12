#include<bits/stdc++.h>
using namespace std;
int main(){
  	string s;
  	cin>>s;
  	bool a0=0,b0=0;
  	for(int i=0;i<s.size();i++){
    	if(s[i]=='A'){
        	a0 = 1;
        }else{
        	b0 = 1;
        }
    }
  	if(a0 && b0){
    	cout<<"Yes";
    }else{
    	cout<<"No";
    }
	return 0;
}
