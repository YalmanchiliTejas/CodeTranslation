
// Problem : W - Intervals
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_w
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define eb emplace_back
#define pb push_back
#define size(s) (int)s.size()
#define int long long
#define vi vector<int>
#define vs vector<string>
#define vv vector<vector<int>>
#define pii pair<int,int>
#define m_p(x,y) make_pair(x,y)
#define vp vector<pair<int,int>>
#define setbits(x) __builtin_popcountll(x)
#define f first
#define se second
#define inc(v,n,x) v.assign(n,x)
#define incd(v,n) v.resize(n)
#define iniz(n) memset(n,0,sizeof(n))
#define inin(n) memset(n,-1,sizeof(n))
#define inimi(n) memset(n,0xc0,sizeof(n))
#define inima(n) memset(n,0x3f,sizeof(n))
#define all(v) (v).begin(),(v).end()
using namespace std;
using namespace __gnu_pbds;
template<typename T1,typename T2>istream &operator>>(istream &is, vector<pair<T1,T2>> &v) { for (pair<T1,T2> &t : v) is >> t.f>>t.se; return is; }
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }
double pi=acos(-1.0);
int md=1e9+7;
const int INF=1e15;
int dx1[]={0,0,-1,1};
int dy1[]={1,-1,0,0};
template<class T>
T abst(T a)
{return a<0?-a:a;}
template<class T> using ordered_set=tree<
T,
null_type,
less_equal<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
struct HASH{
  size_t operator()(const pii &x)const{
    return (size_t) x.first * 37U + (size_t) x.second;}};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int Pow(int n,int x){int ans=1;
 while(x>0)
 {if(x&1)ans=(ans*n)%md;n=(n*n)%md;x=x>>1;}
 return ans;}

 vi fact,inv;
void inverse(int n)
{inv.resize(n+1);inv[0]=1;
for(int i=1;i<=n;i++)inv[i]=Pow(fact[i],md-2);}
void factorial(int n)
{fact.resize(n+1);fact[0]=1;
for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%md;}
int ncr(int n,int r){
return (((fact[n]*inv[r])%md)*inv[n-r])%md;
}
template<class T>
T max2(T a,T b){return a>b?a:b;}
template<class T>
T min2(T a,T b){return a<b?a:b;}

template<class T>
T maxm(initializer_list <T> l){
	T ans=-INF;
	for(T i:l)
	ans=max2(ans,i);
	return ans;
}
vi t,la;
void up(int &a,int &b,int c)
{
	a+=c;
	b+=c;
}
int query(vi &t,int n,int s,int e,int l,int r)
{
	t[n]+=la[n];
	if(s!=e)
	{
		up(la[2*n],la[2*n+1],la[n]);
	}
	la[n]=0;
	if(s>e or s>r or e<l)return INT_MIN;
	
	if(s>=l and e<=r)
	{
		return t[n];
	}
	int mid=(s+e)/2;
	int x=query(t,2*n,s,mid,l,r);
	int y=query(t,2*n+1,mid+1,e,l,r);
	return max2(x,y);
}
void update(vi &t,int n,int s,int e,int l,int r,int val)
{
	t[n]+=la[n];
	if(s!=e)
	{
		up(la[2*n],la[2*n+1],la[n]);
	}
	la[n]=0;
	if(s>e or s>r or e<l)return;
	
	if(s>=l and e<=r)
	{
		t[n]+=val;
		if(s!=e)
		up(la[2*n],la[2*n+1],val);
		return;
	}
	int mid=(s+e)/2;
	update(t,2*n,s,mid,l,r,val);
	update(t,2*n+1,mid+1,e,l,r,val);
	t[n]=max2(t[2*n],t[2*n+1]);
}
bool cmp(pair<int,pii> p1,pair<int,pii> p2)
{
	return p1.se.se<p2.se.se;
}
void solve()
{
int n,m;
cin>>n>>m;
incd(t,4*n+1);
incd(la,4*n+1);
vector<pair<int,pii>> v(m);
for(int i=0;i<m;i++)
cin>>v[i].se.f>>v[i].se.se>>v[i].f;
sort(all(v),cmp);
int ptr=0;
int ans=0;
while(ptr<m and v[ptr].se.se==1)
{
	update(t,1,1,n,v[ptr].se.f,v[ptr].se.se,v[ptr].f);
		ptr++;
}
for(int i=2;i<=n;i++)
{
	int x=query(t,1,1,n,1,i-1);
	x=max2(x,0LL);
	update(t,1,1,n,i,i,x);
	while(ptr<m and v[ptr].se.se==i)
	{
		update(t,1,1,n,v[ptr].se.f,v[ptr].se.se,v[ptr].f);
		ptr++;
	}
}
ans=max2(ans,query(t,1,1,n,1,n));
cout<<ans;
}

int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int t=1;
//cin>>t;
for(int i=1;i<=t;i++)
{
    solve();
}
}
