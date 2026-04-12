#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il void readl(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 105
int n,m;
char map[N][N];
bool vis[N][N];
bool pd(){
	for(int i=1;i<=n;i++){
		bool flag=0;
		int cnt=0;
		for(int j=1;j<=m;j++){
			if(!vis[i][j]){
				if(map[i][j]=='#') flag=1;
			}
			else cnt++;
		}
		if(!flag&&cnt<m) return 0;
	}
	for(int i=1;i<=m;i++){
		bool flag=0;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j][i]){
				if(map[j][i]=='#') flag=1;
			}
			else cnt++;
		}
		if(!flag&&cnt<n) return 0;
	}
	return 1;
}
int main(){
	int i,j;
	in2(n,m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	while(!pd()){
		for(i=1;i<=n;i++){
			bool flag=1;
			for(j=1;j<=m;j++){
				if(!vis[i][j]){
					if(map[i][j]=='#'){
						flag=0;
						break;
					}
				}
			}
			if(flag==1){
				for(j=1;j<=m;j++){
					if(!vis[i][j]) vis[i][j]=1;
				}
			}
		}
		for(i=1;i<=m;i++){
			bool flag=1;
			for(j=1;j<=n;j++){
				if(!vis[j][i]){
					if(map[j][i]=='#'){
						flag=0;
						break;
					}
				}
			}
			if(flag==1){
				for(j=1;j<=n;j++){
					if(!vis[j][i]) vis[j][i]=1;
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		int cnt=0;
		for(j=1;j<=m;j++){
			if(!vis[i][j]) printf("%c",map[i][j]);
			else cnt++;
		}
		if(cnt<m) printf("\n");
	}
	return 0;
}