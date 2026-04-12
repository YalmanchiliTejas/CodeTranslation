#include <bits/stdc++.h>
  
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define SUM(n) ((n)+1)*(n)/2 //1〜nまでの総和を求める式
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) fixed<<setprecision(x+1) //小数点桁数を指定する
#define abs(x,y) max(x,y)-min(x,y)
#define all(v) v.begin(),v.end()
#define UPDigit(a,b) (a+b-1)/b //小数点切り上げ
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD=int(1e9)+7; 
using namespace std;
using pii = pair<lol, lol>;
typedef vector<int> vit;
 
/*
struct SegmentTree{
   
  vector<lol> SumV(1000005,0);
  vector<lol> MaxV(1000005,0);
  vector<lol> MinV(1000005,0);
  int N;
   
  void update(int i,int x){
    i += N - 1;
    minv[i] = x;
    maxv[i] = x;
    sumv[i] = x;
    while(i > 0){
      i = (i - 1)/2;
      maxv[i] = max(maxv[i*2+1],maxv[i*2+2]);
      minv[i] = min(minv[i*2+1],minv[i*2+2]);
      sumv[i] = sumv[i*2+1]+sumv[i*2+2];
    }
  }
   
  void add(int i,int x){
    i += N - 1;
    sumv[i] += x;
    maxv[i] += x;
    minv[i] += x;
    while(i > 0){
      i = (i - 1)/2;
      sumv[i] = sumv[i*2+1]+sumv[i*2+2];
      minv[i] = min(minv[i*2+1],minv[i*2+2]);
      maxv[i] = max(maxv[i*2+1],maxv[i*2+2]);
    }
  }
   
  int getmax(int a,int b,int k,int l,int r){
    if(r <= a || b <= l) return -INF;
    if(a <= l && r <= b) return maxv[k];
    else{
      int c1 = getmax(a,b,2*k+1,l,(l+r)/2);
      int c2 = getmax(a,b,2*k+2,(l+r)/2,r);
      return max(c1,c2);
    }
  }
   
  int getmin(int a,int b,int k,int l,int r){
    if(r <= a || b <= l) return INF;
    if(a <= l && r <= b) return minv[k];
    else{
      int c1 = getmin(a,b,2*k+1,l,(l+r)/2);
      int c2 = getmin(a,b,2*k+2,(l+r)/2,r);
      return min(c1,c2);
    }
  }
   
  int getsum(int a,int b,int k,int l,int r){
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) return sumv[k];
    else{
      int c1 = getsum(a,b,2*k+1,l,(l+r)/2);
      int c2 = getsum(a,b,2*k+2,(l+r)/2,r);
      return c1+c2;
    }
  }
}
*/
 
//最大公約数
lol gcd(lol x, lol y){
  if(x < y) swap(x, y);
  lol r = x % y;
  while(r != 0){
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}
//最小公倍数
lol lcm(lol x, lol y){
  lol a = x * y;
  return (a / gcd(x, y));
}

int n, m, ans = 0;
vit edge[10];
bool isvisited[10] = {false};

void nasu(int x, int sum){
  if(isvisited[x]){
    return;
  }
  if(sum + 1 == n){
    ans ++;
    // cout << x << " ";
    return;
  }
  isvisited[x] = true;
  rep(i, edge[x].size()){
    nasu(edge[x][i], sum + 1);
  }
  isvisited[x] = false;
  return;
}

signed main(void){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  int a, b;
  rep(i, m){
    cin >> a >> b;
    edge[a].pu(b);
    edge[b].pu(a);
  }
  nasu(1, 0);
  cout << ans << '\n';
  return 0;
}
