#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define de(x) cout<<#x<<"="<<x<<endl
	#define rff freopen("input.txt","r",stdin)
#else
	#define de(x)
	#define rff
#endif

#define full_auto(x) for(auto it=x.begin();it!=x.end();it++)
#define pdd pair<double,double>
#define pii pair<int,int>
#define PQ priority_queue
#define setp setprecision
#define sqr(a) ((a)*(a))
#define el cout<<endl
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert
#define re return
#define se second
#define fi first
const int INF=(int)INFINITY;

ll ans;
int n,fa[100003],r[100003];
pii a[100003],x[100003],y[100003];
PQ <pair<int,pii>> q;

int find_fa(int x){
	if (fa[x]==x) return x;
	return fa[x]=find_fa(fa[x]);
}

void uni(int x,int y){
	x=find_fa(x);
	y=find_fa(y);
	if (r[x]<r[y]){
		fa[x]=y;
	}else{
		fa[y]=x;
		if (r[x]==r[y]) r[x]++;
	}
}

int main(){
//	rff;
	cin>>n;
	for (int i=0;i<n;i++){
		fa[i]=i;
	}
	for (int i=0;i<n;i++){
		cin>>a[i].fi>>a[i].se;
		x[i]={a[i].fi,i};
		y[i]={a[i].se,i};
	}
	sort(x,x+n);
	sort(y,y+n);
	for (int i=0;i<n-1;i++){
		q.push({-(x[i+1].fi-x[i].fi),{x[i].se,x[i+1].se}});
		q.push({-(y[i+1].fi-y[i].fi),{y[i].se,y[i+1].se}});
	}
	while (q.size()){
		int c=-q.top().fi,p1=q.top().se.fi,p2=q.top().se.se;
		if (find_fa(p1)!=find_fa(p2)){
			uni(p1,p2);
			ans+=c;
		}
		q.pop();
	}
	cout<<ans;
	re 0;
}