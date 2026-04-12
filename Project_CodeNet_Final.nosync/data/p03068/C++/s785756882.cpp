#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n>>s>>k;
	char c=s[k-1];
	string cnt=""; 
	for(int i=0;i<s.size();i++){
		if(s[i]!=c){
			cnt+='*';
		}
		else if(s[i]==c){
			cnt+=s[i];
		}
	}
	cout<<cnt<<endl;
	return 0;
}