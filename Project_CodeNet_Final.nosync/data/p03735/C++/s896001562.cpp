#include <bits/stdc++.h>
using namespace std;

#define INF 0x3343343343343343
using LLI = long long int;
using Pair = pair<LLI, LLI>;

int N;
int maxi;
int mini;
int size;
LLI xs[214514];
LLI ys[214514];
LLI seg[1 << 23];
LLI seg2[1 << 23];
LLI ans = INF;
Pair ps[214514];

void update(int k, LLI x) {
  k += size-1;
  seg[k] = x;
  while (k > 0) {
    k = (k-1)/2;
    seg[k] = min(seg[k*2+1], seg[k*2+2]);
  }
}

void update2(int k, LLI x) {
  k += size-1;
  seg2[k] = x;
  while (k > 0) {
    k = (k-1)/2;
    seg2[k] = max(seg2[k*2+1], seg2[k*2+2]);
  }
}

LLI query(int wishl, int wishr, int k, int watchl, int watchr) {
  int mid;
  LLI lval, rval;

  if (wishr <= watchl || watchr <= wishl) return INF;
  if (wishl <= watchl && watchr <= wishr) return seg[k];
  
  mid = (watchl+watchr)/2;
  lval = query(wishl, wishr, k*2+1, watchl, mid);
  rval = query(wishl, wishr, k*2+2, mid, watchr);
  return min(lval, rval);
}

LLI query2(int wishl, int wishr, int k, int watchl, int watchr) {
  int mid;
  LLI lval, rval;

  if (wishr <= watchl || watchr <= wishl) return -INF;
  if (wishl <= watchl && watchr <= wishr) return seg2[k];
  
  mid = (watchl+watchr)/2;
  lval = query2(wishl, wishr, k*2+1, watchl, mid);
  rval = query2(wishl, wishr, k*2+2, mid, watchr);
  return max(lval, rval);
}

int main() {
  scanf("%d", &N);
  size = 1;
  while (size < N) size *= 2;

  for (int i=0; i<N; i++) {
    LLI x, y;
    scanf("%lld%lld", &x, &y);
    xs[i] = max(x, y);
    ys[i] = min(x, y);
    ps[i] = Pair(xs[i], ys[i]);
  }

  sort(ps, ps+N);
  for (int i=0; i<N; i++) {
    if (ps[i].first > ps[maxi].first) {
      maxi = i;
    }

    if (ps[i].second < ps[mini].second) {
      mini = i;
    }

    update(i, ps[i].second);
    update2(i, ps[i].second);
  }
  
  if (maxi != mini) {
    multiset<LLI> R;
    LLI bb = ps[maxi].first - ps[mini].second;
    //printf("bb: %lld\n", bb);
    R.insert(ps[maxi].second);
    R.insert(ps[mini].first);
    //printf("R: %lld - %lld\n", *R.begin(), *R.rbegin());

    for (int i=0; i<N; i++) {
      if (i != maxi && ps[i].first >= *R.rbegin()) {
        int ql = lower_bound(ps, ps+N, Pair(ps[i].first+1, -1)) - ps;
        LLI t = query2(ql, N, 0, 0, size);
        if (t <= max(*R.rbegin(), ps[i].first)) {
          LLI rmin = min(query(ql, N, 0, 0, size), *R.begin());
          if (ql > 0) rmin = min(rmin, ps[0].first);
          ans = min(ans, (ps[i].first-rmin)*bb);
        }
      }

      if (i != mini && ps[i].second >= *R.rbegin()) {
        int ql = lower_bound(ps, ps+N, Pair(ps[i].second+1, -1)) - ps;
        LLI t = query2(ql, N, 0, 0, size);
        if (t <= max(*R.rbegin(), ps[i].second)) {
          LLI rmin = min(query(ql, N, 0, 0, size), *R.begin());
          if (ql > 0) {
            if (i != 0) rmin = min(rmin, ps[0].first);
            else if (N > 1 && ql > 1) rmin = min(rmin, ps[1].first);
          }
          ans = min(ans, (ps[i].second-rmin)*bb);
        }
      }
    }
  }

  LLI maxr = -1;
  LLI minb = 1000000001;
  for (int i=0; i<N; i++) {
    maxr = max(maxr, ps[i].second);
    minb = min(minb, ps[i].first);
  }
  ans = min(ans, (maxr-ps[mini].second) * (ps[maxi].first-minb));
  printf("%lld\n", ans);
}
