#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAXN 200005
const lli INF = 1e18+10;
template<typename T>
class SegmentTree
{
	public:
		vector<T> ST,lazy;
		int n;
		T base_value;
		SegmentTree(int n,vector<T> & a){
			this->n = n;
			base_value = INF;//0: sum,gcd 1:multiplication INF:min -INF:max 
			int h = ceil(log2(n));
			ST.resize((1 << (h+1)),base_value);
			lazy.resize((1 << (h+1)),0);
			build(0,n-1,1,a);
		}
		T F(T a,T b){
			return min(a,b);
		}
		void build(int ini,int fin,int pos,vector<T> &a){
			if(ini == fin){
				ST[pos] = a[ini];	
				return;
			}
			int mitad = (ini+fin)/2;
			build(ini,mitad,pos*2,a);
			build(mitad+1,fin,pos*2+1,a);
			ST[pos] =  F(ST[pos*2],ST[pos*2+1]);
		}

		void propagate(int start, int end, int pos, T val){
			ST[pos]+=val;//Min,max
			if(start!=end){
				lazy[pos*2]+=val;
				lazy[pos*2+1]+=val;
			}
		}
		void UpdateLazy(int left,int right,int pos,int start,int end,T val){
			if(lazy[pos] != 0){
				propagate(start,end,pos,lazy[pos]);
				lazy[pos]=0;
			}
			if(end < left || right < start)
				return;
			if(start >= left && end <= right){
				propagate(start,end,pos,val);
				return;
			}
			int mitad = (start+end)/2;
			UpdateLazy(left,right,pos*2,start,mitad,val);
			UpdateLazy(left,right,pos*2+1,mitad+1,end,val);
			ST[pos] = F(ST[pos*2],ST[pos*2+1]);	
		}

		T Query(int start,int end,int pos,int left,int right){
			if(lazy[pos] != 0){
				propagate(start,end,pos,lazy[pos]);
				lazy[pos]=0;
			}
			if(end < left || right < start) 
				return base_value;//0 para suma, -INF para max e INF para min
			if(start >= left && end <= right)
				return ST[pos];

			int mitad = (start+end)/2;
			T izq = Query(start,mitad,pos*2,left,right);
			T der = Query(mitad+1,end,pos*2+1,left,right);
			return F(izq,der);
		}
};
vector<pii> fin[MAXN];

int main(){__
	int n,m;
	cin >> n >> m;
	lli tot =0ll;
	for(int i=0; i < m; i++){
		int l,r,a;
		cin >> l >> r >> a;
		tot+=a;
		fin[r].pb(pii(l,a));
	}

	vector<lli> a(n+2,INF);
	a[0] = 0ll;
	SegmentTree<lli> st(n+2,a);
	lli ans = 0ll;
	for(int i =1; i <=n+1; i++){
		for(auto e : fin[i-1]){
			st.UpdateLazy(0,e.fi-1,1,0,n+1,e.se);
		}
		lli mini = INF;
		mini = st.Query(0,n+1,1,0,n+1);
		if(i == n+1){
			ans = mini;
		}
		st.UpdateLazy(i,i,1,0,n+1,mini - INF);
	}
	cout << tot - ans << endl;
	return 0;
}
