#include <map>
#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;

template<class T> bool chmin(T &a, T b) { return a>b?(a=b,true):false; }
template<class T> bool chmax(T &a,T  b) { return a<b?(a=b,true):false; }
#define forn(i,x,y) for(int i=(x);i<(int)(y);i++)
#define rep(i,y) for(int i=0;i<(int)(y);i++)
#define repb(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)

template<class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << " ";
    os << *it;
  }
  return os;
}

int a[200020];
int b[200020];
int n;
ll ans;
const int mod=1e9+7;
int main() {
    cin >> n;
    rep(i,n) {
        cin>>a[i];
    }
    b[n-1] = a[n-1];
    repb(i,n-1) {
        b[i] = (b[i+1] + a[i]) % mod;
    }
    rep(i,n-1) {
        ans += ((ll)a[i]*b[i+1]) % mod;
        ans %= mod;
    }
    cout<<ans<<endl;
}
