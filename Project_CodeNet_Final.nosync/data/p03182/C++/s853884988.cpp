#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

template <class T>
class Lazy_Segment_Tree{
	private:
	int n;
	vector<T> date,lazy;
	void Set_Lazy(int k,T x){
		date[k]+=x;
		lazy[k]+=x;
	}
	void Push(int k){
		Set_Lazy(k*2+1,lazy[k]);
		Set_Lazy(k*2+2,lazy[k]);
		lazy[k]=0;
	}
	void Fix(int k){
		date[k]=min(date[k*2+1],date[k*2+2]);
	}
	void Add_func(int a,int b,int k,int l,int r,T x){
		if(r<=a||b<=l) return;
		if(a<=l&&r<=b){
			Set_Lazy(k,x);
			return;
		}
		Push(k);
		int m=(l+r)/2;
		Add_func(a,b,k*2+1,l,m,x);
		Add_func(a,b,k*2+2,m,r,x);
		Fix(k);
	}
	void Update_func(int I,int k,int l,int r,T x){
		if(r<=I||I<l) return;
		if(l==I&&r-l==1){
			date[k]=x;
			lazy[k]=x;
			return;
		}
		Push(k);
		int m=(l+r)/2;
		Update_func(I,k*2+1,l,m,x);
		Update_func(I,k*2+2,m,r,x);
		Fix(k);
	}
	T Query_func(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return inf;
		if(a<=l&&r<=b) return date[k];
		Push(k);
		int m=(l+r)/2;
		T vl=Query_func(a,b,k*2+1,l,m);
		T vr=Query_func(a,b,k*2+2,m,r);
		return min(vl,vr);
	}
	public:
	Lazy_Segment_Tree(int n_){
		n=1;
		while(n<n_) n*=2;
		date=lazy=vector<T>(2*n-1);
	}
	void Add(int a,int b,T x){
		Add_func(a,b,0,0,n,x);
	}
	void Update(int k,T x){
		Update_func(k,0,0,n,x);
	}
	T Query(int a,int b){
		return Query_func(a,b,0,0,n);
	}
};

ll n,m;
vl L,R,a;
vp b;

int main(){
	cin>>n>>m;
	L=R=a=vl(m);
	b=vp(m);
	ll res=0,I=0;
	for(int i=0;i<m;i++){
		cin>>L[i]>>R[i]>>a[i];
		b[i]={R[i],i};
		res+=a[i];
	}
	sort(b.begin(),b.end());
	Lazy_Segment_Tree<ll> st(n+2);
	for(int i=0;i<=n;i++){
		while(I<m&&b[I].first==i){
			int id=b[I].second;
			st.Add(0,L[id],a[id]);
			I++;
		}
		ll tmp=st.Query(0,i+1);
		st.Update(i+1,tmp);
		if(i==n) res-=tmp;
	}
	cout<<res<<endl;
}