#include<bits/stdc++.h>
using namespace std;
int f[300],s[300];
int main(){
	int n,i,j;
	string a[100];
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<300;i++)s[i]=10000;
	for(i=0;i<n;i++){
		memset(f,0,sizeof(f));
		for(j=0;j<a[i].size();j++){
			f[a[i][j]]++;
		}
		for(j=0;j<300;j++){
			if(f[j]<s[j]){
				s[j]=f[j];
			}
		}
	}
	for(i=0;i<300;i++){
		for(j=0;j<s[i];j++){
			cout<<char(i);
		}
	}
	return 0;
}

