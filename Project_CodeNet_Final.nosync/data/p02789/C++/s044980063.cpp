
// Problem : A - AC or WA
// Contest : AtCoder Beginner Contest 152
// URL : https://atcoder.jp/contests/abc152/tasks/abc152_a
// Memory Limit : 1024.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define m_p(x,y) make_pair(x,y)
#define vp vector<pair<int,int>>
#define setbits(x) __builtin_popcount(x)
#define f first
#define se second
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

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

void solve()
{
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,m;
cin>>n>>m;
if(n==m)
cout<<"Yes\n";
else
cout<<"No\n";
}

int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int t;
//cin>>t;
t=1;
while(t--)
{
    solve();
}
}
