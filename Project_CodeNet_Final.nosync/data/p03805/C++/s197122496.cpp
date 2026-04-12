
// Problem : C - One-stroke Path
// Contest : AtCoder Beginner Contest 054
// URL : https://atcoder.jp/contests/abc054/tasks/abc054_c
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
#define pb emplace_back
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define vp vector<pair<int,int>>
#define setbits(x) __builtin_popcountll(x)
#define f first
#define se second
#define iniz(n) memset(n,0,sizeof(n))
#define inin(n) memset(n,-1,sizeof(n))
#define inf LLONG_MAX
using namespace std;
template<typename T1,typename T2>istream &operator>>(istream &is, vector<pair<T1,T2>> &v) { for (pair<T1,T2> &t : v) is >> t.f>>t.se; return is; }
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }
double pi=acos(-1.0);
int md=1000000007;
int abst(int a)
{return a<0?-a:a;}
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

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
vi v[8];int count1=0;int n;
void DFS(int x,int p,vi vis)
{
	if(vis[x]==1)return;
	vis[x]=1;
	int k=0;
	for(int i=0;i<n;i++)
	if(vis[i]==0)
	{
		k=1;break;
	}
	if(k!=1)
	{count1++;return;}
	for(int j=0;j<v[x].size();j++)
	if(v[x][j]!=p)
	DFS(v[x][j],x,vis);
}
void solve()
{
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int m;cin>>n>>m;
while(m--)
{
	int x,y;cin>>x>>y;
	x--;y--;
	v[x].pb(y);
	v[y].pb(x);
}
vi vis(n);
DFS(0,-1,vis);
cout<<count1;
}

int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int t=1;
//cin>>t;
while(t--)
{
    solve();
}
}
