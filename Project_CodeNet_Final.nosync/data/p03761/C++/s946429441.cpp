#include <bits/stdc++.h>
using namespace std;
int main (){
	int n,x[26]{},x1[26],y;
	string s[50];
	for(int b=0;b<26;b++)x1[b]=1000;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		y=s[i].size();
		for(int j=0;j<y;j++){
			x[s[i][j]-'a']++;
			}
		for(int k=0;k<26;k++){
			if(x1[k]>=x[k])x1[k]=x[k];
			}
		for(int a=0;a<26;a++)x[a]=0;
		}
	for(int l=0;l<26;l++){
		for(int m=0;m<x1[l];m++){
			cout<<(char)('a'+l);
		}
	}
	cout<<endl;
	return 0;
}
