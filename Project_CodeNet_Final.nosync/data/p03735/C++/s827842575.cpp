#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int maxn=2e5+10;
int n;long long ans=1e18;
struct ddl{int x,y;}a[maxn];multiset<int> A,B;
inline bool operator <(ddl a,ddl b){return a.x<b.x;}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		A.insert(a[i].x);B.insert(a[i].y);
	}
	sort(a+1,a+n+1);
	rep(i,1,n){
		A.erase(A.find(a[i].x));
		B.insert(a[i].x);
		B.erase(B.find(a[i].y));
		A.insert(a[i].y);
		ans=min(ans,1ll*(*A.rbegin()-*A.begin())*(*B.rbegin()-*B.begin()));
	}
	printf("%lld\n",ans);
	return 0;
}