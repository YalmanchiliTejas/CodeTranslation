#include <bits/stdc++.h>
using namespace std;
int main(){
	string input;
	char data[16]={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
	while(1){
		int ans=0;
		cin>>input;
		if(input=="#")break;
		bool key=false;
		for(int i=0;i<15;i++){
			if(data[i]==input[0])key=true;
		}
/*		if(key)cout<<"Left"<<endl;
		else cout<<"Right"<<endl;*/
		for(int i=1;i<input.length();i++){
			bool f=false;
			for(int j=0;j<15;j++){
				if(data[j]==input[i]){
					f=true;
				}
			}
/*			if(f)cout<<"Left"<<endl;
			else cout<<"Right"<<endl;*/
			if(f^key)ans++;
			key=f;
		}
		cout<<ans<<endl;
	}
}