#include<iostream>
#include<string>
using namespace std;

int main(){
	string str, key="hijklmnopyu";
	while(1){
		str.clear();
		cin>>str;
		int ans=0;
		if(str=="#") break;
		
		bool f,s;
		f = (key.find(str[0]) != -1);
		
		for(int i=1;i<str.size();i++){
			s=(key.find(str[i])!=-1);
			if(f^s)ans++;
			f=s;
		}
		cout<<ans<<endl;
	}
	return 0;
}