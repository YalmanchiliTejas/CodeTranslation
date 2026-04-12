#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200][200],sum1[300],sum2[300];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;cin>>c;
			a[i][j]= c=='#' ? 1 : 0;
			sum1[i]+=a[i][j];
			sum2[j]+=a[i][j];
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!sum1[i] || !sum2[j])continue;
			printf(a[i][j]==1 ? "#" : ".");
		}
		if(!sum1[i])continue;
		puts("");
	}
	return 0;
}
