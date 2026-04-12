#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;
struct SegmentTree
{
  const int INF = 1 << 30;
 
  vector< int > small, add;
  int sz;
 
  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    small.assign(2 * sz - 1, 0);
    add.assign(2 * sz - 1, 0);
  }
  inline void Merge(int k)
  {
    small[k] = min(small[2 * k + 1] + add[2 * k + 1], small[2 * k + 2] + add[2 * k + 2]);
  }
  inline int RangeMinimumQuery(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return(INF);
    if(a <= l && r <= b) return(small[k] + add[k]);
    int L = RangeMinimumQuery(a, b, 2 * k + 1, l, (l + r) >> 1);
    int R = RangeMinimumQuery(a, b, 2 * k + 2, (l + r) >> 1, r);
    return(min(L, R) + add[k]);
  }
  int RangeMinimumQuery(int a, int b)
  {
    return(RangeMinimumQuery(a, b, 0, 0, sz));
  }
  inline void RangeAdd(int a, int b, int x, int k, int l, int r)
  {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      add[k] += x;
      return;
    }
    RangeAdd(a, b, x, 2 * k + 1, l, (l + r) >> 1);
    RangeAdd(a, b, x, 2 * k + 2, (l + r) >> 1, r);
    Merge(k);
  }
  void RangeAdd(int a, int b, int x)
  {
    return(RangeAdd(a, b, x, 0, 0, sz));
  }
};

int main()
{
  int N, Q;

  scanf("%d %d", &N, &Q);
  char S[300001];
  scanf(" %s", S);
  SegmentTree tree(N);
  set< int > close;
  for(int i = 0; i < N; i++) {
    tree.RangeAdd(i, N, S[i] == '(' ? +1 : -1);
    if(S[i] == ')') close.insert(i);
  }
  while(Q--) {
    int q;
    scanf("%d", &q);
    --q;
    tree.RangeAdd(q, N, S[q] == ')' ? +2 : -2);
    if(S[q] == '(') {
      close.insert(q);
      S[q] = ')';
      printf("%d\n", *close.begin() + 1);
      tree.RangeAdd(*close.begin(), N, +2);
      S[*close.begin()] = '(';
      close.erase(close.begin());
    } else {
      close.erase(q);
      S[q] = '(';
      int low = -1, high = N - 1;
      while(high - low > 1) {
        int mid = (low + high) >> 1;
        if(tree.RangeMinimumQuery(mid, N) >= 2) high = mid;
        else low = mid;
      }
      while(S[q] == ')') ++high;
      printf("%d\n", high + 1);
      tree.RangeAdd(high, N, -2);
      S[high] = ')';
      close.insert(high);
    }
  }
}