#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	
	char right[11]={'y','u','i','o','p','h','j','k','l','n','m'};
	string s;
	while(1){
		int flag=0;
		cin>>s;
		if(s=="#")break;
		int cnt=0;
		
		for(int i=0;i<11;i++){
			if(s[0]==right[i]){
				flag=1;
				break;
			}
		}
		
		for(int i=1;i<s.size();i++){
			for(int j=0;j<11;j++){
				if(s[i]==right[j]){
					if(flag==0)cnt++;
					flag=1;
					break;
				}
				if(j==10){
					if(flag==1)cnt++;
					flag=0;
				}
			}
			//out<<cnt<<" ";
			
		}
		cout<<cnt<<endl;
		
	}
	return 0;
}