#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define pi pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mp make_pair
#define pb push_back
#define fall(i, a, b) for (int i = a; i < b; i++)
#define sz(x) (ll) x.size()
#define all(x) x.begin(), x.end()
#define ed cout << "ed";
#define time_passed 1.0 * clock() / CLOCKS_PER_SEC
ll MOD = 1e9 + 7;
ll MOD1 = 1e9 + 123;
ll MOD2 = 1e9 + 321;

int main()
{
    fio;
    ll t, a, n, q, k, i, l, m, c, u, f, j, p, x, y, b, d;
   
cin>>n;
vector<int>v(n,0),V(n,0);
for(auto& h : v)
cin>>h;
V[n-1]=0;
for(i=n-2;i>=0;i--)
V[i]=(v[i+1]+V[i+1])%MOD;

// for (auto &h : V)
//     cout<<h<<" ";
//     cout<<endl;

for(i=0;i<n;i++)
V[i]=((v[i]%MOD)*(V[i]%MOD))%MOD;
c=0;
for (i = 0; i < n; i++)
    c = (c + V[i] % MOD) % MOD;
cout<<c<<endl;
    return 0;
}
