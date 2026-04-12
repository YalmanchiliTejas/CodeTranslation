#include <bits/stdc++.h>
using namespace std;
char s[105],a[105][105];
bool h[105],l[105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			a[i][j]=s[j];
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='#'){
				h[i]=true;
				l[j]=true;
			}
	for (int i=1;i<=n;i++)
		if (h[i]){
			for (int j=1;j<=m;j++)
				if (l[j]) cout<<a[i][j];
		printf("\n");
		}
}