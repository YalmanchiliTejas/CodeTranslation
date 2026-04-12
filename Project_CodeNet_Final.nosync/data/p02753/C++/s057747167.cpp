
// Problem : A - Station and Bus
// Contest : AtCoder Beginner Contest 158
// URL : https://atcoder.jp/contests/abc158/tasks/abc158_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb emplace_back
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define m_p(x,y) make_pair(x,y)
#define vp vector<pair<int,int>>
#define setbits(x) __builtin_popcountll(x)
#define f first
#define se second
#define iniz(n) memset(n,0,sizeof(n))
#define inin(n) memset(n,-1,sizeof(n))
using namespace std;
using namespace __gnu_pbds;
template<typename T1,typename T2>istream &operator>>(istream &is, vector<pair<T1,T2>> &v) { for (pair<T1,T2> &t : v) is >> t.f>>t.se; return is; }
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }
double pi=acos(-1.0);
int md=1000000007;
int abst(int a)
{return a<0?-a:a;}
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
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

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
//create(tree,node,a,start,end)
//query(tree,node,start,end,l,r)
//update(tree,node,start,end,index,value)
void solve()
{
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s;cin>>s;
if(find(s.begin(),s.end(),'A')!=s.end() and find(s.begin(),s.end(),'B')!=s.end())
cout<<"Yes";
else
cout<<"No";
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
