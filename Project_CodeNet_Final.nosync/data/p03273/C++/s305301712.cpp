#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main(){
	LL n,m;
	cin>>n>>m;
	char ar[n+1][m+1];
	for(LL i=1;i<=n;i++) for(LL j=1;j<=m;j++) cin>>ar[i][j];
	for(LL i=1;i<=n;i++){
		LL titik=0;
		for(LL j=1;j<=m;j++){
			if (ar[i][j]=='.') titik++;
		}
		if (titik==m) for(LL j=1;j<=m;j++)ar[i][j]='x';
	}
	for(LL j=1;j<=m;j++){
		LL titik=0;
		for(LL i=1;i<=n;i++){
			if (ar[i][j]=='.' || ar[i][j]=='x') titik++;
		}
		if (titik==n) for(LL i=1;i<=n;i++) ar[i][j]='x';
	}
	for(LL i=1;i<=n;i++){
		bool ada=0;
		for(LL j=1;j<=m;j++) if (ar[i][j]!='x') {
			cout<<ar[i][j];
			ada=1;
		}
		if (ada) cout<<endl;
	}
}
