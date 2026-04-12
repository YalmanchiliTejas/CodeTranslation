#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 + 6;

pii p[MAX_N];
LL d[MAX_N];
bool visit[MAX_N];

vector<pii> vx,vy;

map<pii,int> mp;

LL get_dis(pii a,pii b) {
	return min(abs(a.first-b.first),abs(a.second-b.second));
}

pii rev(pii p) {
	return make_pair(p.second,p.first);
}

LL Kirino(int n) {
	LL ret=0;
	visit[mp[p[1]]] = 0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(make_pair(0,mp[p[1]]));
	while (!pq.empty()) {
		pii p=pq.top();
		pq.pop();
		pii pp=vx[p.second];
		if (visit[p.second]) continue;
		ret += p.first;
//		cout<<"pp = "<<pp.first<<" , "<<pp.second<<" , val = "<<p.first<<endl;
		visit[p.second]=1;
		if (p.second + 1<vx.size()) {
			pq.push(make_pair(get_dis(vx[p.second],vx[p.second+1]),p.second+1));
		}
		if (p.second-1 >= 0) {
			pq.push(make_pair(get_dis(vx[p.second],vx[p.second-1]),p.second-1));
		}
		int hor=lower_bound(vy.begin(),vy.end(),rev(pp) ) - vy.begin();
		pp = vy[hor];
		if (hor + 1 < vy.size()) {
			pq.push(make_pair(get_dis(vy[hor],vy[hor+1]),mp[rev(vy[hor+1] )] ));
		}
		if (hor-1>=0) {
			pq.push(make_pair(get_dis(vy[hor],vy[hor-1]),mp[rev(vy[hor-1] )]));
		}
	}
	return ret;
}

int main () {
	int n;
	scanf("%d",&n);
	for (int i=1;n>=i;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		p[i] = make_pair(x,y);
		vx.push_back(make_pair(x,y));
		vy.push_back(make_pair(y,x));
	}
	sort(p+1,p+n+1);
	sort(vx.begin(),vx.end());vx.resize(unique(vx.begin(),vx.end()) - vx.begin());
	int id=0;
	for (auto i:vx) mp[i] = id++;
	sort(vy.begin(),vy.end());vy.resize(unique(vy.begin(),vy.end()) - vy.begin());
	printf("%lld\n",Kirino(n));
}
