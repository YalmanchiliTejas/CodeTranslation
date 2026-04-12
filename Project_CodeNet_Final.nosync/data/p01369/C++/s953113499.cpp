#include<iostream>
#include<string>

using namespace std;
string ld="qwertasdfgzxcvb";
string rd="yuiophjklnm";

int che(char c){
	if(ld.find(c)!=string::npos)return 0;
	return 1;
}
int main(){
	string str;
	while(cin>>str&&str[0]!='#'){
		int old=che(str[0]);
		int ans=0;
		for(int i=1;i<str.size();i++){
			if(old!=che(str[i]))ans++;
			old=che(str[i]);
		}
		cout<<ans<<endl;
	}
}