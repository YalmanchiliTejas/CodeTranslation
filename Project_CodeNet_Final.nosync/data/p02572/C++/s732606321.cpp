#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,e) for(int i=(s);(i)<(int)(e);++(i))
#define REP(i,e) FOR(i,0,e)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define ppb(x) pop_back(x)
#define mp make_pair
#define mt make_tuple
#define t0(t) get<0>((t))
#define t1(t) get<1>((t))
#define t2(t) get<2>((t))

typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 200000;
ll a[N];

int main() {
  int n;
  fscanf(stdin, "%d ", &n);
  REP(i,n) fscanf(stdin, "%lld ", a+i);
  ll res = 0;
  ll b = 0;
  for (int i=n-1; i>=0; i--) {
    if (i < n-1) b = (b + a[i+1]) % mod;
    res = (res + (a[i]*b)%mod) % mod;
  }
  fprintf(stdout, "%lld\n", res);
  return 0;
}
