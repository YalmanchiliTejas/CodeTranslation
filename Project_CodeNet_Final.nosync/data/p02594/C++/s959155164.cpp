#include <bits/stdc++.h>
#include <math.h>
#define lli long long int
#include <limits.h>
#include <fstream>
#define F first
#define S second
#define PI 3.141592653589793238
#define pb push_back

using namespace std;

//doesn't work for arrays
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const lli N=100000;
vector<lli> g[N];
lli low[N],in[N]={0},timer=1;
set<pair<lli,lli>> ans;
bool bridge=0;

lli gcd(lli a,lli b)
{
    if(a==0)
        return b;
    return (b%a,a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli i,j,tt=1;
    //cin>>tt;
    while(tt--)
    {
        lli n;
        cin>>n;
        if(n>=30)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
