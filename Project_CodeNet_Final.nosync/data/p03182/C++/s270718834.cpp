#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
ll lzy[M],mx[M];
void Add(int &c, int ss, int se, int qs, int qe, ll f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return mx[c];
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe)+lzy[c];
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe)+lzy[c];
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
vector<pair<int,int>> seg[N];
int main()
{
	int n,m,i,l,r,x;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=m;i++) scanf("%i %i %i",&l,&r,&x),seg[r].pb(mp(l,x));
	for(int i=1;i<=n;i++)
	{
		Add(root,0,n,i,i,Get(root,0,n,0,i-1));
		for(auto p:seg[i]) Add(root,0,n,p.first,i,p.second);
	}
	printf("%lld\n",Get(root,0,n,0,n));
	return 0;
}