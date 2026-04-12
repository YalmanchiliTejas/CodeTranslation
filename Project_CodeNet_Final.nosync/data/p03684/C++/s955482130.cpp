#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int xx[MAXN],yy[MAXN],ata[MAXN],p[MAXN];
bool cmp1(int x,int y){
	return (xx[x]<xx[y]);
}
bool cmp2(int x,int y){
	return (yy[x]<yy[y]);
}
int tap(int x){
	if(x==ata[x])
		return x;
	return ata[x]=tap(ata[x]);	
}
bool merge(int x,int y){
	if((x=tap(x))==(y=tap(y)))
		return 0;
	ata[y]=x;return 1;	
}
int main(){
    //~ freopen("file.in", "r", stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",xx+i,yy+i);
		p[i]=i;ata[i]=i;
	}
	vector<pair<int,PII> >edges;
	sort(p+1,p+n+1,cmp1);
	for(int i=1;i<n;i++)
		edges.pb(mp(xx[p[i+1]]-xx[p[i]],mp(p[i],p[i+1])));
	sort(p+1,p+n+1,cmp2);
	for(int i=1;i<n;i++)
		edges.pb(mp(yy[p[i+1]]-yy[p[i]],mp(p[i],p[i+1])));
	sort(all(edges));
	int ans=0;
	tr(it,edges)
		if(merge(it->ss.ff,it->ss.ss))
			ans+=it->ff;
	printf("%d\n",ans);	
	return 0;
}
