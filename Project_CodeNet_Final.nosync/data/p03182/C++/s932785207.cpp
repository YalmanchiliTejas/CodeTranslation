#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

typedef pair<ll, ll> pl;

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[i*2+1], node[i*2+2]);
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }

        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return -1000000000000000000;
        if(a <= l && r <= b) return node[k];
        ll vl = query(a, b, 2*k+1, l, (l+r)/2);
        ll vr = query(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int main(int argc, char const *argv[]) {
  //左、-1, 追加
  // 右、左、減らす
  ll n, m;std::cin >> n >> m;
  multimap<ll, pl> mp;
  for(int i=0;i<m;i++){
    ll a, b, c;std::cin >> a >> b >> c;
    mp.emplace(a, pl(-1, c));
    mp.emplace(b+1, pl(a, c));
  }
  auto itr = mp.begin();
  LazySegmentTree seg(vll(n+1, 0));

  ll ans = 0;
  for(int i=1;i<=n;i++){
    while(itr!=mp.end()&&(*itr).first==i){
      pl top = (*itr).second;

      if(top.first==-1){
        seg.add(0, i, top.second);
      }else{
        seg.add(0, top.first, -top.second);
      }

      itr++;
    }
    ll q = seg.query(0, i);
    ans = max(ans, q);
    seg.add(i, i+1, q);
  }
  std::cout << ans << '\n';
  return 0;
}
