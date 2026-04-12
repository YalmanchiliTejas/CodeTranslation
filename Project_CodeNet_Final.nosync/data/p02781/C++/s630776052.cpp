#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	string s;
	int k;
	cin>>s>>k;
	long long ans=0;
	if(k==1){
		for(int i=0;i<s.size();i++){
			if(i==0){
				ans+=(s[i]-'0');
			}else{
				ans+=9;
			}
		}
		cout<<ans<<endl;
	}else if(k==2){
		for(int i=1;i<s.size();i++){
			ans+=(s[0]-'0'-1)*9;
			bool f=true;
			for(int j=1;j<i;j++){
				if(s[j]!='0'){
					f=false;
				}
			}
			if(f){
				ans+=(s[i]-'0');
			}else{
				ans+=9;
			}
		}
		for(int i=1;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				ans+=81;
			}
		}
		cout<<ans<<endl;
	}else{
		for(int i=1;i<s.size();i++){
			bool f=true;
			for(int j=1;j<i;j++){
				if(s[j]!='0'){
					f=false;
				}
			}
			for(int j=i+1;j<s.size();j++){
				ans+=(s[0]-'0'-1)*81;
				if(f){
					bool g=true;
					for(int k=i+1;k<j;k++){
						if(s[k]!='0'){
							g=false;
						}
					}
					if(g){
						if(s[i]!='0'){
							ans+=(s[i]-'0'-1)*9;
							ans+=(s[j]-'0');
						}
					}else{
						ans+=(s[i]-'0')*9;
					}
				}else{
					ans+=81;
				}
			}
		}
		for(int i=1;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				for(int k=j+1;k<s.size();k++){
					ans+=729;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
