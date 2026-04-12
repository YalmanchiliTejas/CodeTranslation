#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		bool flag=false;
		for(int i=1;i<3;i++){
			if(s[i]!=s[0]){
				flag=true;
			}
		}
		if(flag==false){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
	
} 