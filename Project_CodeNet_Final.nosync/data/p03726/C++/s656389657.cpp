#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define pb push_back
#define pa pair<int,int>
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<"\n"
using namespace std;
inline int read(){int w=1,s=0;char ch=getchar();while(!isdigit(ch)){if(ch=='-') w=-1;ch=getchar();} while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();} return w*s;}
struct node{int to,next;} e[1010010];
int n,h[1010100],tot,f[101010],g[101001];
inline void add(int from,int to){e[++tot].next=h[from];h[from]=tot;e[tot].to=to;}
inline void DFS(int now,int ffa){
	int Max=-1e9;
	for(rint i=h[now];i;i=e[i].next){
		int to=e[i].to;if(to==ffa) continue;
		DFS(to,now);g[now]+=f[to];Max=max(Max,g[to]-f[to]);
	}f[now]=g[now]+Max+1;
}
int main(){
	n=read();
	for(rint i=1;i<n;++i) {int x=read(),y=read();add(x,y);add(y,x);}
	if(n&1){
		cout<<"First\n";
		return 0;
	}
	else {
		DFS(1,0);
		if(f[1]==n/2){
			cout<<"Second\n";
			return 0;
		}
		else cout<<"First\n";
	}
	return 0;
}	