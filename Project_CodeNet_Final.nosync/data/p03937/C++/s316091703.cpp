#include<stdio.h>
#include<algorithm>
using namespace std;
char in[10][10];
int cnt[20];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",in[i]);
	for(int i=0;i<a;i++)for(int j=0;j<b;j++)if(in[i][j]=='#')cnt[i+j]++;
	for(int i=0;i<a+b-1;i++)if(cnt[i]!=1){printf("Impossible\n");return 0;}
	printf("Possible\n");
}