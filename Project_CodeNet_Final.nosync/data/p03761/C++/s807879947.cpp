#include<iostream>
using namespace std;
int n,i,j,a[26],c[26];
string s;
int main(){
	cin>>n;
	for(i=0;i<26;i++)a[i]=50;
	for(i=0;i<n;i++){
		cin>>s;
		for(auto x:s)c[x-'a']++;
		for(j=0;j<26;c[j++]=0)a[j]=min(a[j],c[j]);
	}
	for(i=0;i<26;i++)while(a[i]--)cout<<(char)('a'+i);
	cout<<endl;
	return 0;
}