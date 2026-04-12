#include<bits/stdc++.h>
#define maxn 200050
#define LL long long
using namespace std;
struct node
{
	LL fi,se;
}a[maxn];
multiset<LL>m1,m2;
int cmp(node a,node b){
	if(a.fi==b.fi) return a.se<b.se;
	return a.fi<b.fi;
}
int main(){
//	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].fi,&a[i].se);
		if(a[i].fi>a[i].se) swap(a[i].fi,a[i].se);
		m1.insert(a[i].fi),m2.insert(a[i].se);
	}
	sort(a+1,a+1+n,cmp);
	LL ans=(*m1.rbegin()-*m1.begin())*(*m2.rbegin()-*m2.begin());
	for(int i=1;i<=n;i++){
		m1.erase(m1.find(a[i].fi)),m2.erase(m2.find(a[i].se));
		m1.insert(a[i].se),m2.insert(a[i].fi);
		ans=min(ans,(*m1.rbegin()-*m1.begin())*(*m2.rbegin()-*m2.begin()));
	}
	printf("%lld\n",ans);
	return 0;
}