#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int k;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>s>>k;
	s="#"+s; 
	for(int i=1;i<=n;i++){
		if(s[i]!=s[k])
			s[i]='*';
		cout<<s[i];
	}
	return 0;
}
