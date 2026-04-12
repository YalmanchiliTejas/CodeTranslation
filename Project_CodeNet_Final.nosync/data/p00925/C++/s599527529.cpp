#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string s;
	int n,f;
	cin>>s>>n;
	int k=s[0]-'0';
	for(int i=1;i<s.size();i+=2){
		if(s[i]=='+')k+=(s[i+1]-'0');
		else k*=(s[i+1]-'0');
	}
	f=(k==n);
	int a=s[0]-'0',c=0;
	for(int i=1;i<s.size();i+=2){
		if(s[i]=='+'){
			c+=a;
			a=s[i+1]-'0';
		}
		else{
			a*=(s[i+1]-'0');
		}
	}
	c+=a;
	f+=(2*(c==n));
	cout<<"ILMU"[f]<<endl;
	
	return 0;
}
