#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
#define mem(a,b) memset(a,b,sizeof(a))
int n,m;
char ch[110][110];
int l[110],r[110];
int main(){
	int i,j,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",ch[i]);
	}
	mem(l,0);mem(r,0);
	for(i=0;i<n;i++){
		int flag=1;
		for(j=0;j<m;j++){
			if(ch[i][j]=='#'){
				flag=0;break;
			}
		}
		if(flag) l[i]=1;
	}
	for(j=0;j<m;j++){
		int flag=1;
		for(i=0;i<n;i++){
			if(ch[i][j]=='#'){
				flag=0;break;
			}
		}
		if(flag) r[j]=1;
	}
	int flag=0;
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<m;j++){
			if(!l[i]&&!r[j]){
				flag=1;
				printf("%c",ch[i][j]);
			}
		}
		if(flag)
			printf("\n");
	}
	return 0;
}