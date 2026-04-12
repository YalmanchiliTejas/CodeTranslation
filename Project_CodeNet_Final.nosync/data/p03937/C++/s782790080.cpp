#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[10][10];
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (s[i][j]=='#'){
		if (i!=1||j!=1){
			int cnt=0;
			if (s[i-1][j]=='#') cnt++;
			if (s[i][j-1]=='#') cnt++;		
			if (cnt>1) return puts("Impossible"),0;
		}
		if (i!=n||j!=m){
			int cnt=0;
			if (s[i+1][j]=='#') cnt++;
			if (s[i][j+1]=='#') cnt++;		
			if (cnt>1) return puts("Impossible"),0;
		}
	}
	if (s[1][1]!='#'||s[n][m]!='#') return puts("Impossible"),0;
	puts("Possible");
	return 0;
}