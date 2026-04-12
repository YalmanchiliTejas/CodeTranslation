#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <ctime>
#include <queue>
#include <sstream>
#include <utility>
#include <bitset>

using namespace std;

#define MP make_pair 
#define PB push_back 
#define MOD (1000000007) 
#define eps 1e-8
const int INF=1000000007;

typedef pair<int,int> pii ;
typedef long long ll ;

int n,s,ss;
pii po[100005],rr[100005],rc[100005],rub[100005];
int p[100005],indr[100005],indc[100005];
map<pii,bool> m;
priority_queue<pair<int,pii> > q;
ll ans;

inline bool cmpr(int x,int y)
{
	return po[x].first<po[y].first;
}

inline bool cmpc(int x,int y)
{
	return po[x].second<po[y].second;
}

int FIND(int x)
{
	if(p[x]!=x) return p[x]=FIND(p[x]);
	return x;
}

void UNION(int x,int y)
{
	int rx=FIND(x),ry=FIND(y);
	if(rx!=ry) 
	{
		p[rx]=p[ry];
	}
}

inline int dis(pii x,pii y)
{
	return min(abs(x.first-y.first),abs(x.second-y.second));
}

inline void PUSHR(int i)
{
	int ret=INF,tmp;
	rr[i].first--;
	rr[i].second++;
	if(rr[i].first>0) 
	{
		if(dis(po[indr[rr[i].first]],po[i])<ret) ret=dis(po[indr[rr[i].first]],po[i]),tmp=1;
	}
	if(rr[i].second<=n) 
	{
		if(dis(po[indr[rr[i].second]],po[i])<ret) ret=dis(po[indr[rr[i].second]],po[i]),tmp=2;
	}
	if(tmp==1 && rr[i].first>0) 
	{
		rr[i].second--;
		q.push(MP(-ret,MP(i,indr[rr[i].first])));
	}
	else if(tmp==2 && rr[i].second<=n)
	{
		rr[i].first++;
		q.push(MP(-ret,MP(i,indr[rr[i].second])));
	} 
}

inline void PUSHC(int i)
{
	int ret=INF,tmp;
	rc[i].first--;
	rc[i].second++;
	if(rc[i].first>0) 
	{
		if(dis(po[indc[rc[i].first]],po[i])<ret) ret=dis(po[indc[rc[i].first]],po[i]),tmp=1;
	}
	if(rc[i].second<=n) 
	{
		if(dis(po[indc[rc[i].second]],po[i])<ret) ret=dis(po[indc[rc[i].second]],po[i]),tmp=2;
	}
	if(tmp==1 && rc[i].first>0) 
	{
		rc[i].second--;
		q.push(MP(-ret,MP(i,indc[rc[i].first])));
	}
	else if(tmp==2 && rc[i].second<=n)
	{
		rc[i].first++;
		q.push(MP(-ret,MP(i,indc[rc[i].second])));
	} 
}

int main()
{
	cin>>ss;
	for(int i=1;i<=ss;i++)
	{
		cin>>rub[i].first>>rub[i].second;
		if(m[rub[i]]) continue;
		n++;
		po[n]=rub[i];
		m[po[n]]=1;
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
		indr[i]=i;
		indc[i]=i;
	}
	sort(indr+1,indr+1+n,cmpr);
	sort(indc+1,indc+1+n,cmpc);
	for(int i=1;i<=n;i++)
	{
		rr[indr[i]]=MP(i,i);
		rc[indc[i]]=MP(i,i);
	}
	for(int i=1;i<=n;i++)
	{
		PUSHR(i);
		PUSHC(i);
	}
	for(;s<n-1;)
	{
		int t=-q.top().first;
		pii tp=q.top().second;
		q.pop();
		int fr=tp.first,to=tp.second;
//		cout<<t<<" "<<fr<<" "<<to<<endl;
		PUSHC(fr);
		PUSHC(to);
		PUSHR(fr);
		PUSHR(to);
		if(FIND(fr)==FIND(to)) continue;
		UNION(fr,to);
		ans+=t;

		s++;
	}
	cout<<ans;
	return 0;
}