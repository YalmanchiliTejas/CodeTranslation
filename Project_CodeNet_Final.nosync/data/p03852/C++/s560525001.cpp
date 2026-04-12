
#include <bits/stdc++.h>
#include <ext/rope>
#define VALHALLA cin.tie(0);ios_base::sync_with_stdio(false);cout<<fixed<<setprecision(13);cerr<<fixed<<setprecision(5);
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define debug(x) std::cerr << #x << ": " << (x) << '\n';
#define sz(x) (int)x.size()
#define fast(map_name) map_name.reserve(1024);map_name.max_load_factor(0.25);
using namespace std;
using namespace __gnu_cxx;
typedef long long int ll;
typedef pair<int,int> ii;
typedef complex<double> point;
const double epsilon=1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
/* VARIABLE DECLARATION START */
int globe[int(1e6)];
/*  FUCNTION TEMPLATE STARTS  HERE */
double dot(point a,point b){ return (conj(a)*b).real() ; }
double cross(point a,point b){ return (conj(a)*b).imag() ; }
double dist(point a, point b){ return abs(a-b); }
struct neal {
static uint64_t splitmix64(uint64_t x)
 {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const
 {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}
};
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return (size_t) x.first * 37U + (size_t) x.second;
  }
};
bool isprime(ll n) {
    if (n == 2 || n == 3) return true;
    if (n < 2 || n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 6; (i - 1) * (i - 1) <= n; i += 6) {
        if (n % (i - 1) == 0 || n % (i + 1) == 0) {
            return false;
        }
    }
    return true;
}
inline ll exp(ll a, ll b, ll mod) {
    ll n = 1;
    ll p = a;
    while (b > 0) {
        if (b % 2 == 1) {
            n *= p;
            n %= mod;
        }
        p *= p;
        p %= mod;
        b /= 2;
    }
    return n;
}

inline bool comp(double a,double b)
{
  return (fabs(a-b)<epsilon);
}
inline int maxm(const int &a,const int &b)
{
  if(a>b)return a;
  else return b;
}
ll gcd(ll u, ll v) {
  ll r;
  while (0 != v) {
    r = u % v; u = v; v = r;
  }
  return u;
}
/*  FUCNTION TEMPLATE ENDS HERE */

int main()
{
   VALHALLA
   string x;cin>>x;
   string s="aeiou";
   if(s.find(x)!=string::npos)
    cout<<"vowel"<<endl;
  else
    cout<<"consonant"<<endl;

}

