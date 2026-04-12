#include <bits/stdc++.h>
#define LP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int c,hs;
	string s;
	while(1){
		cin>>s;
		if(s=="#") break;
		hs=-1;
		c=0;
		for(int i=0;i<s.size();i++){
			if(((s[i]-'a')==20||(s[i]-'a')==24)&&hs!=1){
				hs=1;
				c++;
			}
			else if((s[i]-'a')==25&&hs!=0){
				hs=0;
				c++;
			}
			if((s[i]-'a')<=6&&hs!=0){
				hs=0;
				c++;
			}
			else if((s[i]-'a')>6&&(s[i]-'a')<=15&&hs!=1){
				hs=1;
				c++;
			}
			else if((s[i]-'a')>15&&(s[i]-'a')<=19&&hs!=0){
				hs=0;
				c++;
			}
			else if((s[i]-'a')>20&&(s[i]-'a')<=23&&hs!=0){
				hs=0;
				c++;
			}
		}
		cout<<c-1<<endl;
	}
	return 0;
}
