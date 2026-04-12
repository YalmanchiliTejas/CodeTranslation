#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
    int f=1,x=0;char s=getchar();   
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}  
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}
#define MAXN 10
#define INF 0x3f3f3f3f
char Map[MAXN+5][MAXN+5];
int main(){
	int h=read(),w=read(),cnt=0;
	for(int i=1;i<=h;i++){
		scanf("%s",Map[i]+1);
		for(int j=1;j<=w;j++)
			if(Map[i][j]=='#')
				cnt++;
	}
	if(cnt!=h+w-1){
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(Map[i][j]=='#'&&Map[i+1][j-1]=='#'){
				puts("Impossible");
				return 0;
			}
	puts("Possible");
	return 0;
}