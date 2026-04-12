#include<bits/stdc++.h>
using namespace std;
//Optimisations
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
//shortcuts for functions
#define pb push_back
#define mp make_pair
#define ff first 
#define ss second
#define all(v) v.begin(),v.end()
#define prec(n) fixed<<setprecision(n)
#define n_l '\n'
// make it python 
#define gcd __gcd
#define append push_back
#define str to_string
// utility functions shortcuts
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define sswap(a,b) {a=a^b;b=a^b;a=a^b;}
#define swap(a,b) {auto temp=a; a=b; b=temp;}
#define init(dp) memset(dp,-1,sizeof(dp));
#define set0(dp) memset(dp,0,sizeof(dp));
#define bits(x) __builtin_popcount(x)
#define SORT(v) sort(all(v))
#define endl "\n"
#define forr(i,n) for(ll i=0;i<n;i++)
// declaration shortcuts
typedef long long int ll;
#define int ll
// Constants
constexpr int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr ll INF = 1999999999999999997; 
constexpr int inf= INT_MAX;
constexpr int MAXSIZE = int(8e5)+5;
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr auto MOD = 1000000007;
constexpr auto MOD9 = 1000000009;
constexpr auto maxn = 100006;
//void IOfile(){
//freopen(file_name, reade_mode, stdin);
//freopen(file_name, write_mode, stdout);
//}
void fastio(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

int tree[MAXSIZE];
int lazy[MAXSIZE];
int a[MAXSIZE];

void build(int node, int left, int right){
	if(left==right){
		tree[node] = a[left];
		return ;
	}
	int mid = (left+right)/2;
	build(2*node, left,mid);
	build(2*node+1,mid+1,right);
	tree[node] = max(tree[2*node],tree[2*node+1]);
}

void propogate(int node, int left, int right){
	if(lazy[node]!=0){
		tree[node]+=lazy[node];
		if(left!=right){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node] = 0;	
	}
	
}

void update(int node, int left, int right, int l, int r, int val){
	propogate(node,left,right);
	if(left>r || right<l || right<left) return ;
	if(left>=l and right<=r){
		tree[node] = val;
		return ;
	}
	int mid = (left+right)/2;
	update(2*node,left,mid,l,r,val);
	update(2*node+1,mid+1,right,l,r,val);
	tree[node] = max(tree[2*node],tree[2*node+1]);
}

int query(int node, int left, int right, int l, int r){
	propogate(node,left,right);
	if(left>r || right<l || right<left) return -mod;
	if(left>=l and right<=r) return tree[node];
	int mid = (left+right)/2;
	int p = query(2*node,left,mid,l,r);
	int q = query(2*node+1,mid+1,right,l,r);
	return max(p,q);
}

int cnt[2*maxn];
int b[2*maxn];

int32_t main(){
	fastio();
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
		cnt[i] = i;
	}
	build(1 , 1 , n);
	for(int i = 1; i <= n; i++){
		if(cnt[i] != i) continue;
		int ind  = i;
		bool ok = true;
		while(ok){
			ok = false;
			int get = ind;
			int low = ind + 1, high = n;
			while(low <= high){
				int mid = (low + high)/2;
				int k = query(1,1 , n , ind + 1, mid);
				if(k > b[ind]){
					ok = true;
					
					get = mid;
					high  = mid  -1;
				}else low = mid + 1;
			}
			
			cnt[get] = cnt[ind];
			update(1,1,n,get,get,-1);
			if(ok) ind = get;
		}
		
		
	}
	set<int>ans;
	for(int i = 1; i <= n; i++){
		ans.insert(cnt[i]);
		//cout << cnt[i] << " ";
	}
	cout << ans.size();
}