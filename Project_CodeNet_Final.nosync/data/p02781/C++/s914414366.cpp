#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=103;
int k,sum,s1;
char s[N];
int f[N][5][2];
int main() {
	scanf("%s",s);
	int len=strlen(s);
	scanf("%d",&k);
	f[0][0][0]=1;
	f[0][1][0]=s[0]-'1';
	f[0][1][1]=1;
	for(int i=0;i<len;i++)
		for(int j=0;j<=k;j++) {
			f[i+1][j][0]+=f[i][j][0];//i+1  0
			f[i+1][j+1][0]+=f[i][j][0]*9;//i+1  1~9
			if(s[i+1]=='0') f[i+1][j][1]+=f[i][j][1]; //i+1  0
			else {
				f[i+1][j+1][1]+=f[i][j][1];//i+1  s[i+1]
				f[i+1][j+1][0]+=f[i][j][1]*(s[i+1]-'1');
				f[i+1][j][0]+=f[i][j][1];
			}
		}
	printf("%d\n",f[len-1][k][0]+f[len-1][k][1]);
	return 0;
}