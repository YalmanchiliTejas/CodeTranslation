#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL 9223372036854775
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define MOD 998244353
#define MOD9 998244353
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

#define int long long

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a)  begin((a)), end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

const int MAX_N = 200005;
const int MAX_M = 200005;

int N, M;
struct Input {
  int l,r,x;
};

using II = pair<int, int>;

Input inputs[MAX_M];
vector<int> add[MAX_N];
vector<II> del[MAX_N];

#define MAX_SEG (2 << 20)

struct Node{
  int sum;
  int delay;
  bool delayFlag;
  Node(){
    sum = delay = delayFlag = 0;
  }
};

int n;
Node seg[2*MAX_SEG];

//セグメントツリーの要素数の設定
void Init(int _n){
  n = 1;
  while(_n > n)
    n *= 2;
}

//遅延値の評価
inline void DelayEvaluate(int k, int a, int b){

  //遅延評価フラグが立っていないなら遅延評価を行わない
  if(!seg[k].delayFlag)
    return;

  //現在の値を遅延値に基づいて更新
  seg[k].sum += seg[k].delay;
  
  //今見ているノードに子がある場合
  if(k < n-1){
    //遅延値を子に伝播させる
    seg[2*k+1].delay += seg[k].delay;
    seg[2*k+2].delay += seg[k].delay;
    //遅延評価フラグを立てる
    seg[2*k+1].delayFlag = seg[2*k+2].delayFlag = true;
  }

  //遅延評価を行ったので自分の遅延値等は初期化しておく
  seg[k].delay = seg[k].delayFlag = 0;

}

//ノードkの値の計算
//子の値が計算終了していることが前提
inline void UpdateNode(int k){
  seg[k].sum = max(seg[2*k+1].sum, seg[2*k+2].sum);
}

//[l,r)の範囲一様にvを加算する
void UpdateRange(int l, int r, int v, int k = 0, int a = 0, int b = n){

  //とりあえず遅延計算
  DelayEvaluate(k,a,b);
  
  //見ているノードが[l,r)と全く被っていない場合
  if(b <= l || r <= a){
    return;
  }
  //完全に被っている場合
  else if(l <= a && b <= r){
    seg[k].delay += v;
    seg[k].delayFlag = true;
    DelayEvaluate(k,a,b);
    return;
  }
  //ちょい被りの場合
  else{
    int mid = (a+b)/2;
    UpdateRange(l,r,v,2*k+1,a,mid);
    UpdateRange(l,r,v,2*k+2,mid,b);
    UpdateNode(k);
    return;
  }

}

//[l,r)の値の合計を出力する
int Query(int l, int r, int k = 0, int a = 0, int b = n){

  //とりあえず遅延計算
  DelayEvaluate(k,a,b);

  //今見ているノードが[l,r)と全く被っていない場合
  if(b <= l || r <= a)
    return -1145141919810;
  //完全に被っている場合
  else if(l <= a && b <= r){
    return seg[k].sum;
  }
  //ちょい被りの場合
  else{
    int vl,vr;
    int mid = (a+b)/2;
    vl = Query(l,r,2*k+1,a,mid);
    vr = Query(l,r,2*k+2,mid,b);
    return max(vl,vr);
  }

}


signed main()
{
  cin >> N >> M;
  Init(N);
  REP(m,M) {
    Input& n = inputs[m];
    cin >> n.l >> n.r >> n.x;
    add[n.l].emplace_back(n.x);
    del[n.r].emplace_back(II(n.l, n.x));
  }

  int ans = 0;
  FOR(n,1,N+1) {
    for(int x : add[n]) {
      UpdateRange(0,n,x);
    }
    int ma = Query(0,n);
    ans = max(ans, ma);
    UpdateRange(n,n+1,ma);
    for(auto p : del[n]) {
      UpdateRange(0,p.first,-p.second);
    }
    // cerr << n << ": " << ma << endl;
    // REP(nn,N+1) {
    //   cerr << Query(nn,nn+1) << " ";
    // }
    // cerr << endl;
  }

  cout << ans << endl;

  return 0;
}