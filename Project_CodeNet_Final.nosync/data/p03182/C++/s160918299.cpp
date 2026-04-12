#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
ll n,m;
vll in[200009],out[200009];
ll l[200009],r[200009],a[200009];
ll dp[200009];
struct NODE{
	ll lzy,tree;
	NODE *left,*right;
	NODE(){
		lzy=tree=0;
		left=right=NULL;
	}
}*root=new NODE;
void lzyUPD(NODE *node,ll l,ll r){
	node->tree+=node->lzy;
	if(node->left!=NULL)node->left->lzy+=node->lzy;
	if(node->right!=NULL)node->right->lzy+=node->lzy;
	node->lzy=0;
}
void upd(NODE *node,ll l,ll r,ll s,ll e,ll x){
	lzyUPD(node,l,r);
	if(s<=l && e>=r){
		node->lzy+=x;
		lzyUPD(node,l,r);
		return ;
	}
	if(s<=mid){
		if(node->left==NULL)node->left=new NODE;
		upd(node->left,l,mid,s,e,x);
	}
	else if(node->left!=NULL)lzyUPD(node->left,l,mid);
	if(e>=mid+1){
		if(node->right==NULL)node->right=new NODE;
		upd(node->right,mid+1,r,s,e,x);
	}
	else if(node->right!=NULL)lzyUPD(node->right,mid+1,r);
	ll mx=-inf;
	if(node->left!=NULL)mx=max(mx,node->left->tree);
	if(node->right!=NULL)mx=max(mx,node->right->tree);
	node->tree=mx;
}
ll query(NODE *node,ll l,ll r,ll s,ll e){
	lzyUPD(node,l,r);
	if(l>e || s>r)return -inf;
	if(s<=l && e>=r)return node->tree;
	ll mx=-inf;
	if(node->left!=NULL)mx=max(mx,query(node->left,l,mid,s,e));
	if(node->right!=NULL)mx=max(mx,query(node->right,mid+1,r,s,e));
	return mx;
}
int main(){
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		cin>>l[i]>>r[i]>>a[i];
		in[l[i]].pb(i);
		out[r[i]].pb(i);
	}
	for(ll i=1;i<=n;i++){
		ll sum=0;
		for(auto u:in[i])sum+=a[u];
		upd(root,0,n,0,i-1,sum);
		dp[i]=query(root,0,n,0,i-1);
		upd(root,0,n,i,i,dp[i]);
		for(auto u:out[i])upd(root,0,n,0,l[u]-1,-a[u]);
	}
	ll mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,dp[i]);
	cout<<mx<<endl;
}
