#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>
#include <random>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define uid uniform_int_distribution<lli>
#define lli long long int
#define ff first
#define ss second
#define pb push_back
#define popf pop_front()
#define popb pop_back()
#define all(vec) vec.begin(), vec.end()
#define fol(i,a,b) for(int i=a;i<b;i++)
#define forr(x,arr) for(auto& x:arr)
#define sz(x) (x.size())
#define mod 1000000007
#define INF 1000000000000000010
#define vi vector<int>
#define vlli vector<lli>
#define endl "\n"
#define ofk order_of_key
#define fbo find_by_order
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class my>
using indexed_set = tree<my,null_type,less<my>,rb_tree_tag,tree_order_statistics_node_update>;

template <class my>
inline my aabs (const my &a)   { return (a > 0)  ? a : -a;         }
inline lli gcd(lli a, lli b)   { return (b == 0) ? a : gcd(b,a%b); }
inline lli LSOne(lli k)        { return (k&(-k));                  }

inline int inv(lli o, int m = mod) {
  int b = m, u = 0, v = 1, t, a=o%m;
  while (a) {
    t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  if (u < 0) u += m;
  return u;
}
inline int add(const int &a, const int &b, int m=mod) { return ( a + b ) % m;           }
inline int sub(const int &a, const int &b, int m=mod) { return ( a - b + m ) % m;       }
inline int mul(const int &a, const int &b, int m=mod) { return int ( 1LL * a * b % m ); }
inline int mpow(int a, int b, int m=mod) {
    int ans = 1;
    a=((a%m)+m)%m;
    while (b) {
        if (b & 1) ans = mul(ans, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return ans;
}

void tejas_919()
{
    lli n, k, m, q, u=0, v=0, temp=1, max1=-1, max2=-1, ans=0, a, b, val=0;
    cin>>n;
    multiset<int> se;
    fol(i,0,n)
    {
        cin>>temp;
        auto itr=se.lower_bound(temp);
        if(itr!=se.begin()) se.erase(--itr);
        se.insert(temp);
    }
    cout<<se.size()<<endl;
}

int main()
{
    fastio cout<<endl;
    cout << fixed << setprecision(10);
    int t=1;
    //cin>>t;
    while(t--)
        tejas_919();
}
