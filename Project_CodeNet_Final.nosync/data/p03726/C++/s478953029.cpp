#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define inf 1000000005
#define mod 1000000007
#define put putchar('\n')
#define F(i,a,b) for (int i=a;i<=b;i++)
#define D(i,a,b) for (int i=a;i>=b;i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}
int x,y,n,m,vis[N],dui[N],r,in1[N];
int nedge,head[N*2],to[N*2],Next[N*2];
#define V to[i]
void add(int a,int b){
   Next[++nedge]=head[a];head[a]=nedge;to[nedge]=b;
}
signed main(){
	n=read();
	F(i,1,n-1){
		x=read();y=read();add(x,y);add(y,x);in1[x]++;in1[y]++;
	}
	F(i,1,n){
		if (in1[i]==1) dui[++r]=i,vis[i]=1;
	}
	F(l,1,r){
		int t=dui[l];
		go(i,t){
			if (vis[V]!=2){
				vis[V]=vis[t]=2;
				go(j,V){
					in1[to[j]]--;
					if (in1[to[j]]==1&&vis[to[j]]==0) dui[++r]=to[j];
				}
				break;
			}
		}
	}
	F(i,1,n){
		if (vis[i]!=2) return puts("First"),0;
	}
	puts("Second");
	return 0;
}