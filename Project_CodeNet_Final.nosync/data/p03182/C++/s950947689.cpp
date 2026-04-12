#include <bits/stdc++.h>
//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//~ using namespace __gnu_pbds; 
#define mp make_pair
#define endl '\n'
typedef long long ll;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=2e5+5;
const int mod=1e9+7;	
const ll oo=1e18+5;

//~ typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

class IT{
	struct node{
		int left,right;
		ll val,lazy;
	};
	vector<node> a;
	void push_down(int id){
		ll plus=a[id].lazy;
		a[id].lazy=0;
		a[id<<1].val+=plus;
		a[id<<1].lazy+=plus;
		a[id<<1|1].val+=plus;
		a[id<<1|1].lazy+=plus;
	}
	void push_up(int id){
		a[id].val=max(a[id<<1].val,a[id<<1|1].val);
	}
	void build(int l,int r,int id){
		a[id].left=l,a[id].right=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,id<<1);
		build(mid+1,r,id<<1|1);
	}
	public:
	IT(int n):a(n<<2){
		build(0,n,1);
	}
	void add(int l,int r,ll val,int id=1){
		if(a[id].left>=l&&a[id].right<=r){
			a[id].val+=val;
			a[id].lazy+=val;
			return;
		}
		push_down(id);
		int mid=(a[id].left+a[id].right)>>1;
		if(l<=mid) add(l,r,val,id<<1);
		if(r>mid) add(l,r,val,id<<1|1);
		push_up(id);
	}
	ll get_max(int l,int r,int id=1){
		if(l<=a[id].left&&a[id].right<=r) return a[id].val;
		push_down(id);
		ll maxx=-9e18;
		int mid=(a[id].left+a[id].right)>>1;
		if(l<=mid) maxx=max(maxx,get_max(l,r,id<<1));
		if(r>mid) maxx=max(maxx,get_max(l,r,id<<1|1));
		push_up(id);
		return maxx;
	}
};

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<ll> beg(n+1);
	vector<vector<pair<int,ll>>> fin(n+1);
	for(int i=0;i<m;++i){
		int l,r;
		ll val;
		cin>>l>>r>>val;
		beg[l]+=val;
		fin[r].emplace_back(l,val);
	}
	IT tree(n+1);
	ll ans=0;
	for(int i=1;i<=n;++i){
		// put 1 here 
		// add all vals start from i
		tree.add(0,i-1,beg[i]);
		ll cur_max=tree.get_max(0,i-1); 
		ans=max(ans,cur_max);
		tree.add(i,i,cur_max); // add cur in here 
		for(pair<int,ll> x:fin[i]){
			tree.add(0,x.first-1,-x.second);
		}
	}
	cout<<ans;
	return 0;	
}
