#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tr[1600001];
ll lz[1600001];
void push(int in){
  tr[in] += lz[in];
  lz[2 * in] += lz[in];
  lz[2 * in + 1] += lz[in];
  lz[in] = 0;
}
ll get(int in, int l, int r, int s, int e){
  push(in);
  if(l > e || r < s)
    return -1e18;
  if(l >= s && r <= e)
    return tr[in];
  int m = (l + r) / 2;
  return max(get(2 * in, l, m, s, e), get(2 * in + 1, m + 1, r, s, e));
}
void add(int in, int l, int r, int s, int e, ll v){
  push(in);
  if(l > e || r < s)
    return;
  if(l >= s && r <= e){
    lz[in] += v;
    push(in);
    return;
  }
  int m = (l + r) / 2;
  add(2 * in, l, m, s, e, v);
  add(2 * in + 1, m + 1, r, s, e, v);
  tr[in] = max(tr[2 * in], tr[2 * in + 1]);
}
struct E{
  int in, v;
  int l, r;
  bool add;
};
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
//  add(1, 0, n - 1, 0, 0, 10);
//  cout << get(1, 0, n - 1, 0, n - 1);
//  return 0;
  vector<E> es(2 * m);
  for(int i = 0;i < m;i++){
    int l, r, v;
    scanf("%d %d %d", &l, &r, &v);
    l--, r--;
    es[2 * i].in = l;
    es[2 * i].l = l;
    es[2 * i].r = r;
    es[2 * i].v = v;
    es[2 * i].add = true;
    es[2 * i + 1].in = r + 1;
    es[2 * i + 1].l = l;
    es[2 * i + 1].r = r;
    es[2 * i + 1].v = v;
    es[2 * i + 1].add = false;
  }
  sort(es.begin(), es.end(), [](const E& a, const E& b){
    return a.in < b.in;
  });
//  for(auto el : es){
//    cout << el.in << ' ' << el.l << ' ' << el.r << ' ' << el.v << ' ' << el.add << endl;
//  }
  int cure = 0;
  ll dp[n];
  ll cursum = 0;
  ll mx = 0;
  for(int i = 0;i < n;i++){
    while(cure < 2 * m && es[cure].in == i){

      if(es[cure].add){
        cursum += es[cure].v;
        add(1, 0, n - 1, es[cure].l, es[cure].r, -es[cure].v);
      }else{
        cursum -= es[cure].v;
        add(1, 0, n - 1, es[cure].l, es[cure].r, es[cure].v);
      }
      cure++;
    }
//    if(i)
//      cout << get(1, 0, n - 1, 0, i - 1) << ' ';
//    for(int j = 0;j < n;j++){
//      cout << get(1, 0, n - 1, j, j) << ' ';
//    }
//    cout << endl;
    dp[i] = cursum;
    if(i){
      dp[i] = max(dp[i], cursum + get(1, 0, n - 1, 0, i - 1));
    }
    add(1, 0, n - 1, i, i, dp[i]);
//    cout << cursum << endl;
//    cout << dp[i] << endl;
//    for(int j = 0;j < n;j++){
//      cout << get(1, 0, n - 1, j, j) << ' ';
//    }
//    cout << endl;
    mx = max(mx, dp[i]);
  }
  cout << mx;
  return 0;
}
