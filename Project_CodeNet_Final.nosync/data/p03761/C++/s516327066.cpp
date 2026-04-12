#include<bits/stdc++.h>
using namespace std;
int n,f[30][55];
string s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++)f[s[j]-'a'+1][i]++;
	}
	for(int i=1;i<=30;i++){
		int k=1e9;
		for(int j=1;j<=n;j++)
			k=min(k,f[i][j]);
		if(k==0)continue;
		for(int j=1;j<=k;j++)printf("%c",i+'a'-1);
	}
	printf("\n");
	return 0;
}