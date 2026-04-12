#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		if(s=="#"){
			break;
		}
		int v=0;
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='y' || s[i]=='u' || s[i]=='i' || s[i]=='o' || s[i]=='p' || s[i]=='h' || s[i]=='j' || s[i]=='k' || s[i]=='l' || s[i]=='n' || s[i]=='m'){
				if(v==2){
					ans++;
				}
				v=1;
			}
			else{
				if(v==1){
					ans++; 
				}
				v=2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}