#include<bits/stdc++.h>
using namespace std;
string s;
int n,lens,a[27],ac[27];
int main(){
	memset(ac,127,sizeof(ac));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		lens=s.size();
		memset(a,0,sizeof(a));
		for(int j=0;j<lens;j++)
			a[s[j]-'a']++;
		for(int j=0;j<26;j++)
			if(a[j]<ac[j])ac[j]=a[j];
	}
	for(int i=0;i<26;i++)
		for(int j=1;j<=ac[i];j++)
			printf("%c",i+97);
	cout<<endl;
}