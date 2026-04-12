#include<bits/stdc++.h>
using namespace std;
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define int long long int 
#define fi first
#define se second
#define FIO {ios::sycnt2_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);}
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define pow10(n) stoll("1"+string(n,'0'))
//fill(all(arr),1)
//if(map.count(key)){}
//bitset<20>(n);
//int mini=min({a,b,c,d,e});
#define int long long int
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef long double ld;
#define mod 1000000007
int32_t main()
{
  int n;
  cin>>n;
  int a[n];
  forn(i,n)
  {
    cin>>a[i];
  }
  int sum=0;
  int ans=0;
  forn(i,n)
  {
    ans+=((sum%mod)*a[i])%mod;
    sum+=a[i]%mod;
  } 
  cout<<ans%mod;
}