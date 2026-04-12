 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>
 
using namespace std;

const int N=100010;

int n,x,y;
int dsu[N];
struct edge {
	int a,b,val;
	bool operator<(const edge& rhs) const {
		return val<rhs.val;
	}
}; 
vector<edge> vec;
vector<PII> v1,v2;

int fi(int x) {
	return dsu[x]==x?x:(dsu[x]=fi(dsu[x]));
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x,&y);
		v1.pb(mp(x,i+1));v2.pb(mp(y,i+1));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for (int i=1;i<n;i++) {
		vec.pb({v1[i].second,v1[i-1].second,v1[i].first-v1[i-1].first});
		vec.pb({v2[i].second,v2[i-1].second,v2[i].first-v2[i-1].first});
	}
	for (int i=1;i<=n;i++) dsu[i]=i;
	sort(vec.begin(),vec.end());
	ll ans=0;
	for (auto& e:vec) {
		int r1=fi(e.a);
		int r2=fi(e.b);
		if (r1!=r2) {
			ans+=e.val;
			dsu[r1]=r2;
		}
	}
	printf("%lld\n",ans);
}
