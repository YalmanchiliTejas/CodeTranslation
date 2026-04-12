#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

const int N=200005;
const int inf=1000000000;

struct node{
	int x,y;
	node(){}
	node(int x,int y):x(x),y(y){}
}a[N],b[N];
int p1,p2,n,m,s1,s2,mn,mx;
ll ans;
int c[N];

ll solve1(){
	int i;
	s1=a[p1].y-a[p2].y;
	s2=a[p1].x-a[p2].x;
	for (i=1;i<=n;i++) if (i!=p1&&i!=p2){
		s1=max(s1,a[p1].y-a[i].y);
		s2=max(s2,a[i].x-a[p2].x);
	}
	return 1ll*s1*s2;
}

bool cmp1(node a,node b){
	return a.x<b.x;
}

bool cmp2(node a,node b){
	return a.y<b.y;
}

void work(int mxl,int mnl,int id){
	int i,cnt=0;
	for (i=1;i<=m;i++) if (i!=id){
		if (b[i].y<=mxl){
			mnl=min(mnl,b[i].y);
			cnt++;
			continue;
		}
		if (b[i].x<=mxl) mnl=min(mnl,b[i].x);
		else return;
	}
	s2=min(s2,mxl-mnl);
}

void check(int mxl,int mnl){
	s2=min(s2,mxl-mnl);
}

ll solve2(){
	int i,j,mxx;
	mn=min(a[p1].x,a[p2].y);
	mx=max(a[p1].x,a[p2].y);
	s1=a[p1].y-a[p2].x;
	s2=inf;
	for (i=1;i<=n;i++)
		if (i!=p1&&i!=p2) b[++m]=a[i];
	sort(b+1,b+1+m,cmp1);
	work(max(mx,b[m].x),mn,m); mxx=b[m].x;
	sort(b+1,b+1+m,cmp2);
	c[m+1]=inf; j=0;
	for (i=m;i>=1;i--) c[i]=min(c[i+1],b[i].x);
	for (i=1;i<=m;i=j+1) if (b[i].y>=mxx){
		j=i;
		while (j<m&&b[j+1].y==b[j].y) j++;
		check(max(mx,b[i].y),min(mn,min(b[1].y,c[j+1])));
	}
	else j=i;
	return 1ll*s1*s2;
}

int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	p1=p2=1;
	for (i=1;i<=n;i++){
		if (a[i].y>a[p1].y) p1=i;
		if (a[i].x<a[p2].x) p2=i;
	}
	if (p1==p2){
		for (i=1;i<=n;i++){
			if (a[i].y==a[p1].y&&i!=p2){
				p1=i;
				break;
			}
			if (a[i].x==a[p2].x&&i!=p1){
				p2=i;
				break;
			}
		}
	}
	ans=solve1();
	if (p1!=p2) ans=min(ans,solve2());
	printf("%lld\n",ans);
	return 0;
}