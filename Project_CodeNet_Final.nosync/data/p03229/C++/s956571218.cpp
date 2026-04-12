#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

typedef long long ll;

typedef std::pair<int, int> ipair;
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
bool morePair(const ipair& l, const ipair& r){return l.second > r.second;}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = 1e9 + 7;
// const long long INF = 1LL<<60;
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }
void sub(long long &a, long long b) { a -= b; if (a < 0) a += MOD; }
void mul(long long &a, long long b) { a *= b; a %= MOD; }
ll llmin(ll a, ll b) { if (a < b) return a; else return b; }
ll llmax(ll a, ll b) { if (a < b) return b; else return a; }
ll llabs(ll a) { if (a >= 0) return a; else return - a; }
ll llmodpow(ll a, ll n) {
   if (n == 0) return 1;
   ll tmp = llmodpow(a, n / 2);
   mul(tmp, tmp);
   if (n & 1) mul(tmp, a);
   return tmp;
}

int main() {
   int N;
   cin >> N;
   int a[N];
   for (int i = 0; i < N; i++) cin >> a[i];
   sort(a, a + N);
   reverse(a, a + N);

   ll ans = 0;
   if (N % 2 == 0) {
      int k = N / 2;
      for (int i = 0; i < k - 1; i++) {
         ans += 2 * a[i];
      }
      ans += a[k - 1];
      ans -= a[k];
      for (int i = k + 1; i < N; i++) {
         ans -= 2 * a[i];
      }
   } else {
      int k = N / 2;
      for (int i = 0; i < k; i++) {
         ans += 2 * a[i];
      }
      ans += a[k];
      ans += a[k + 1];
      for (int i = k; i < N; i++) {
         ans -= 2 * a[i];
      }
      ll tmp = 0;
      for (int i = 0; i < k + 1; i++) {
         tmp += 2 * a[i];
      }
      tmp -= a[k - 1];
      tmp -= a[k];
      for (int i = k + 1; i < N; i++) {
         tmp -= 2 * a[i];
      }
      if (ans < tmp) ans = tmp;
   }
   cout << ans << endl;
   return 0;
}
