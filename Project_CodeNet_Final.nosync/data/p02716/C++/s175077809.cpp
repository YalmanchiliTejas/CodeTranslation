
// Problem : F - Select Half
// Contest : AtCoder Beginner Contest 162
// URL : https://atcoder.jp/contests/abc162/tasks/abc162_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define eb emplace_back
#define pb push_back
#define int long long
#define vi vector<int>
#define vv vector<vector<int>>
#define pii pair<int,int>
#define m_p(x,y) make_pair(x,y)
#define vp vector<pair<int,int>>
#define setbits(x) __builtin_popcountll(x)
#define f first
#define se second
#define inc(v,n,x) v.resize(n,x)
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
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
const int INF=1e15;
template <class T>
T max1( std::initializer_list<T> list )
{	 T ans=-INF; for( auto elem : list ) ans= max(ans,elem); return ans;}
template <class T>
T min1( std::initializer_list<T> list )
{	 T ans=-INF; for( auto elem : list ) ans= min(ans,elem); return ans;}
void solve()
{
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;cin>>n;vi v(n+1);for(int i=1;i<=n;i++)cin>>v[i];
int dp[n+1][2];
dp[1][1]=-INF;dp[1][0]=0;
dp[2][0]=v[1],dp[2][1]=v[2];
dp[3][0]=max(v[2],v[1]);dp[3][1]=v[3];
int sumo=0;sumo+=v[1]+v[3];
for(int i=4;i<=n;i++){
	if(i%2==0){
		dp[i][0]=sumo;
		dp[i][1]=v[i]+max1({dp[i-1][0],dp[i-2][0],dp[i-2][1]});
	}
	else
	{
		sumo+=v[i];
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=v[i]+max1({dp[i-2][0],dp[i-2][1],dp[i-3][0],dp[i-3][1]});
	}
}
cout<<max1({dp[n][1],dp[n][0]});
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
