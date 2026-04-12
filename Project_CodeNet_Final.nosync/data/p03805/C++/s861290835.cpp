#include <bits/stdc++.h>
#define LL long long
#define FOR(i,c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define F first
#define S second
using namespace std;

const LL mod = 1e9 + 7;

template<typename T> T gcd(T a, T b) { return b == 0?a: gcd(b, a % b); }
template<typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
template<typename T, typename S> T expo(T b, S e, const T &m){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m;}
template<typename T, typename S> T expo(T b, S e){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b), e>>1): (b*expo((b*b), e>>1));}
template<typename T, typename S> T modinv(T a, S mod) { return expo(a, mod-2, mod); }
template<class T, class S> std::ostream& operator<<(std::ostream &os, const std::pair<T, S> &t) {
	os<<"("<<t.first<<", "<<t.second<<")";
	return os;
}
template<class T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &t) {
	os<<"["; FOR(it,t) { if(it != t.begin()) os<<", "; os<<*it; } os<<"]";
	return os;
}

const int MAXN = 10;

int n, m;
bool mat[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  int a, b;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    mat[a][b] = mat[b][a] = true;
  }
  vector<int> perm(n, 0);
  for(int i = 0; i < n; i++) {
    perm[i] = i + 1;
  }
  LL res = 0;
  do {
    int p = 1;
    bool ok = true;
    for(int i = 1; i < perm.size(); i++) {
      if(!mat[p][perm[i]]) {
        ok = false;
        break;
      }
      p = perm[i];
    }
    if(ok) res++;
  } while(next_permutation(next(perm.begin()), perm.end()));
  cout << res << '\n';
  return 0;
}
