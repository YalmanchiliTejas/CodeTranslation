#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,cnt;
char s[15][15];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%s",s[i]);
		for(int j=0;j<m;j++){
			if(s[i][j]=='#') cnt++;
		}
	}
	if(cnt==n+m-1) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}
