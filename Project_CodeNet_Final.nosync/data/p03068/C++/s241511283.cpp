#include<bits/stdc++.h>
using namespace std;
int main(){
	char ch[20];
	int n,k;
	cin>>n;
	cin>>ch;
	cin>>k;
	char temp=ch[k-1];
	for(int i=0;i<strlen(ch);i++)
		if(ch[i]!=temp)cout<<'*';
		else cout<<ch[i];
	return 0;
}