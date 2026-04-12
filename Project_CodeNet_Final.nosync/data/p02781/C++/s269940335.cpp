#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1111;
char s[N];
int c[N],t[N];
int n,k,sum,cnt=1;
int check(){
	for (int i=1; i<=n; i++)
		if (s[i]-'0'!=t[i])	return s[i]-'0'>t[i];
	return 1;
}
void dfs(int dep,int x){
	if (dep==k+1){
		if (c[1]!=1){
			sum=sum+cnt;
			return;
		}
		if (k==1){
			for (int i=1; i<=9; i++){
				for (int w=1; w<=n; w++)	t[w]=0;
				t[c[1]]=i;
				if (check())	sum++;
			}
		}
		if (k==2){
			for (int i=1; i<=9; i++)
			for (int j=1; j<=9; j++){
				for (int w=1; w<=n; w++)	t[w]=0;
				t[c[1]]=i,t[c[2]]=j;
				if (check())	sum++;
			}
		}
		if (k==3){
			for (int i=1; i<=9; i++)
			for (int j=1; j<=9; j++)
			for (int l=1; l<=9; l++){
				for (int w=1; w<=n; w++)	t[w]=0;
				if (k>=1)	t[c[1]]=i;
				if (k>=2)	t[c[2]]=j;
				if (k>=3)	t[c[3]]=l;
				if (check())	sum++;
			}
		}
		return;
	}
	for (int i=x+1; i<=n; i++){
		c[dep]=i;
		dfs(dep+1,i);
	}
}
int main(){
	scanf("%s%d",s+1,&k);
	for (int i=1; i<=k; i++)	cnt=cnt*9;
	n=strlen(s+1);
	dfs(1,0);	
	printf("%d\n",sum);
	return 0;
}