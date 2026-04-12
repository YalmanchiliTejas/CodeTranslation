#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") 
 
#include<bits/stdc++.h>
 
#define CFOR(i, str) for(int i = 0; (str)[i]!='\0'; (i)++)
#define FOR(i, s, r) for(int i = (s); i < (r); i++)
#define INF 1e9
#define NINF -1e9
#define SUM(a) accumulate(a.begin(), a.end(), 0)
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.rbegin(), v.rend())
#define vmax(v) *max_element(v.begin(), v.end())
#define vmin(v) *min_element(v.begin(), v.end())
#define cnt(v, n) count(v.begin(), v.end(), (n))
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vpii vector<pair<int, int>>
#define vpic vector<pair<int, char>>
#define mp make_pair
#define rot(s, k) rotate(s.begin(), s.begin()+ s.size()-(k%s.size()), s.end()); //+ve = right, -ve = left
#define lld long long int
#define ulld unsigned long long int
typedef long long ll;
using namespace std;
 
ll binpow(ll a, ll b) { 
ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;
}
 
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
 
bool isPrime(ll n) { 
    if (n <= 1) return false; 
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (ll i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; 
    return true; 
}
void solve(){
      lld n,m;
    cin>>n>>m;
    if(n==m)
   cout<<"Yes\n";
   else
   cout<<"No\n";
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   t=1;
   while(t--)
   { 
   solve();
   }
   return 0;
}