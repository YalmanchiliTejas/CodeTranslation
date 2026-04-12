#include<bits/stdc++.h>
using namespace std;
int a[26];
void pd(string x){
	int l=x.size();
	int n[26];
	memset(n,0,sizeof(n));
	for(int i=0;i<l;i++)
		n[x[i]-'a']++;
	for(int i=0;i<26;i++)
		a[i]=min(n[i],a[i]);
	return;
}
int main(){
	int n;
	string x;
	cin>>n;
	memset(a,9999,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>x;
		pd(x);
	}
	for(int i=0;i<26;i++)
		for(int j=0;j<a[i];j++)
			cout<<char(i+'a');
	return 0;
}