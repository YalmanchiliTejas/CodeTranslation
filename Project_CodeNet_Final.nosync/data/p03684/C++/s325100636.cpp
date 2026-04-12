#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define up(i,j,n)	for(int i=j;i<=n;i++)
#define down(i,j,n)	for(int i=j;i>=n;i--)
#define cmax(a,b)	a=max(a,b)
#define cmin(a,b)	a=min(a,b)
#define pii		pair<int,int>
#define fi		first
#define	se		second
#define SZ(x)		(int)x.size()

const int MAXN=1e5+5;
const int oo=0x3f3f3f3f;

int N,fa[MAXN];
struct Axe{
	int x,y,p;
}axe[MAXN],tmp;

int operator - (Axe a,Axe b){
	return min(abs(a.x-b.x),abs(a.y-b.y));
}

vector<Axe>edge;

ll ans=0;

namespace solution{
	inline bool cmpx(Axe a,Axe b){return a.x<b.x;}
	inline bool cmpy(Axe a,Axe b){return a.y<b.y;}
	inline bool cmpp(Axe a,Axe b){return a.p<b.p;}
	int getf(int k){
		if(k==fa[k])return k;
		fa[k]=getf(fa[k]);
		return fa[k];
	}
	void Prepare(){
		scanf("%d",&N);
		up(i,1,N){
			axe[i].p=i;
			scanf("%d%d",&axe[i].x,&axe[i].y);
		}
	}
	void Solve(){
		up(i,1,N)fa[i]=i;
		sort(axe+1,axe+N+1,cmpx);
		up(i,1,N){
			if(i!=1){
				tmp.x=axe[i].p;tmp.y=axe[i-1].p;
				tmp.p=axe[i]-axe[i-1];
				edge.push_back(tmp);
			}
			if(i!=N){
				tmp.x=axe[i].p;tmp.y=axe[i+1].p;
				tmp.p=axe[i]-axe[i+1];
				edge.push_back(tmp);
			}
		}
		sort(axe+1,axe+N+1,cmpy);
		up(i,1,N){
			if(i!=1){
				tmp.x=axe[i].p;tmp.y=axe[i-1].p;
				tmp.p=axe[i]-axe[i-1];
				edge.push_back(tmp);
			}
			if(i!=N){
				tmp.x=axe[i].p;tmp.y=axe[i+1].p;
				tmp.p=axe[i]-axe[i+1];
				edge.push_back(tmp);
			}
		}
		sort(edge.begin(),edge.end(),cmpp);
		up(i,0,SZ(edge)-1){
			int x=edge[i].x,y=edge[i].y,v=edge[i].p;
			x=getf(x);y=getf(y);
			if(x!=y){
				fa[x]=y;
				ans+=v;
			}
		}
		cout<<ans<<endl;
	}
}

int main(){
//	freopen("input.in","r",stdin);
	using namespace solution;
	Prepare();
	Solve();
	return 0;
}