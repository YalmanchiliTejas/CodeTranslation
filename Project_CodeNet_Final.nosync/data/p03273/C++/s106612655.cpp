#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
char a[maxn][maxn];
int l[maxn];
int c[maxn];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",a[i]);
		for(int i=0;i<n;i++){
			int flag = 1;
			for(int j=0;j<m;j++){
				if(a[i][j]=='#'){
					flag = 0;
					break;
				}
			}
			if(flag)l[i] = 1;
		}
		for(int i=0;i<m;i++){
			int flag = 1;
			for(int j=0;j<n;j++){
				if(a[j][i]=='#'){
					flag = 0;
					break;
				}
			}
			if(flag)c[i] = 1;
		}
		for(int i=0;i<n;i++){
			int flag = 0;
			for(int j=0;j<m;j++){
				if(l[i]||c[j])continue;
				printf("%c",a[i][j]);
				flag = 1;
			}
			if(flag)
			printf("\n");
		}
	return 0;
}