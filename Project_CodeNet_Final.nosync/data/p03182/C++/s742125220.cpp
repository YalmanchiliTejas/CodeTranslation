#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAXN=2e5+10;
const LL INF=0x3f3f3f3f;
vector<pii> bck[MAXN];
int n,m;
LL sum;

struct Segment_tree{
	#define lson (nod<<1)
	#define rson ((nod<<1)|1)
	#define mid ((tree[nod].lef+tree[nod].rig)>>1)
	
	struct Pt{
		int lef,rig;
		LL mn,vl;
	}tree[MAXN<<2];
	
	void build(int nod,int l,int r){
		tree[nod].lef=l;
		tree[nod].rig=r;
		if(l==r) return; 
		build(lson,l,mid);
		build(rson,mid+1,r);
	}
	
	void plus(int nod,int l,int r,LL val){
		if(l<=tree[nod].lef&&tree[nod].rig<=r){
			tree[nod].mn+=val;
			tree[nod].vl+=val;
			return;
		}
		pushdown(nod);
		if(l<=mid) plus(lson,l,r,val);
		if(r>mid) plus(rson,l,r,val);
		update(nod);
	}
	
	void pushdown(int nod){
		tree[lson].mn+=tree[nod].vl;
		tree[rson].mn+=tree[nod].vl;
		tree[lson].vl+=tree[nod].vl;
		tree[rson].vl+=tree[nod].vl;
		tree[nod].vl=0;
	}
	
	void update(int nod){
		tree[nod].mn=min(tree[lson].mn,tree[rson].mn);
	}
	
	LL query(int nod,int l,int r){
		if(l<=tree[nod].lef&&tree[nod].rig<=r){
			return tree[nod].mn;
		}
		pushdown(nod);
		LL ret=INF;
		if(l<=mid) ret=min(ret,query(lson,l,r));
		if(r>mid) ret=min(ret,query(rson,l,r));
		return ret;
	}
	
	void change(int nod,int x,LL val){
		if(tree[nod].lef==x&&tree[nod].rig==x){
			tree[nod].mn=val;
			tree[nod].vl=val;
			return;
		}
		pushdown(nod);
		if(x<=mid) change(lson,x,val);
		else change(rson,x,val);
		update(nod);
	}
	
	#undef lson
	#undef rson
	#undef mid
} tree;

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		bck[b].push_back(make_pair(a,c));
		sum+=c;
	}
	
	tree.build(1,0,n);
	
	for(int i=1;i<=n;i++){
		LL d=tree.query(1,0,i-1);
		tree.change(1,i,d);
		pii t;
		int len=bck[i].size();
		for(int j=0;j<len;j++){
			t=bck[i][j];
			tree.plus(1,0,t.first-1,t.second);
		}
	}
	
	cout<<sum-tree.query(1,0,n)<<endl;
	
	return 0;
}
 