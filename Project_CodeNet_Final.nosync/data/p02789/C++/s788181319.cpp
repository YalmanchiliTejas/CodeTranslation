#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define M2 998244353
#define ll long long
#define pll pair<long, long>
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define ff first
#define ss second
#define pb push_back
#define db pop_back
#define mp make_pair
#define mt make_tuple
#define g(a, b) get<a>(b)
#define INF (ll)1e18 + 100
#define vl vector<ll>
#define vi vector<int>
#define vll vector<pair<ll, ll>>
#define vii vector<pair<int, int>>
#define all(v) v.begin(),v.end()
#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x − 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

#define o_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll modI(ll a, ll m);
ll gcd(ll a, ll b);
ll powM(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
ll logint(ll x,ll y);
 
 
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
 
ll modI(ll a, ll m)
{
   return powM(a, m-2, m);
}
 
void pairsort(int a[],int b[],int n)
{
    pair<int,int> v[n];
    REP(i,0,n)
    {
        v[i].ff=a[i];
        v[i].ss=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].ff;
        b[i]=v[i].ss;
    }
}
 
void pairsortll(ll a[],ll b[],ll n)
{
    pair<ll,ll> v[n];
    REP(i,0,n)
    {
        v[i].ff=a[i];
        v[i].ss=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].ff;
        b[i]=v[i].ss;
    }
}
 
ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<=x;i++)
    {
        if(x<a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}
/*const int N = 2e5+5;
ll parent[N];
ll siz[N];
void make(){
    REP(i, 0, N){
        parent[i]=i;
        siz[i] = 1;
    }
}
ll find(ll x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}
void unite(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a] < siz[b]){
            swap(a, b);}
        parent[b] = a;
        if(siz[a] == siz[b]){
            siz[a]++;
        }
    }
} */
/*pair<ll, string> hashtable[100005];
int hashfunc(ll x){
    return x%100001;
}
string search(ll x){
    int j = hashfunc(x);
    while(hashtable[j].ff != x && hashtable[j].ss != ""){
        j = (j+1)%100001;
    }
    return hashtable[j].ss;
}
 
void insert(ll x, string s){
    int j = hashfunc(x);
    while(hashtable[j].ss != ""){
        j = (j+1)%100001;
    }
    hashtable[j].ff = x;
    hashtable[j].ss = s;
}*/
 
ll extended(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extended(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}
ll lcm(ll x, ll y){
    return (x*y)/__gcd(x,y);
}
//const int  N = 1e5+5;
//vector<ll>v[N];
//map<ll,vl > m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m;
    cin>>n>>m;
    if(n==m){cout<<"Yes";}
    else{
        cout<<"No";
    }
}