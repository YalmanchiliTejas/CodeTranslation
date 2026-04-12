#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b;
bool flag,vis[101];
char s[101][101];
int main(){
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",s[i]);
	for(int i=0;i<b;i++){
		flag=0;
		for(int j=0;j<a;j++)
			if (s[j][i]=='#')flag=1;
		if (!flag)vis[i]=1;
	}
	for(int i=0;i<a;i++){
		flag=0;
		for(int j=0;j<b;j++)
			if (s[i][j]=='#')flag=1;
		if (flag){
			for(int j=0;j<b;j++)
				if (!vis[j])printf("%c",s[i][j]);
			printf("\n");
		}
	}
} 