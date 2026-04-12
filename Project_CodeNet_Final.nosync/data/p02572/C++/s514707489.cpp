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
using pii = pair<int, int>;
typedef vector<int> vit;
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

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
  
signed main(void){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  lol a[n + 5];
  reps(i, n){
    cin >> a[i];
  }
  lol sum[n + 5] = {};
  for(int i = n;i > 0;i --){
    sum[i] += a[i];
    sum[i] %= MOD;
    sum[i - 1] += sum[i];
  }
  lol ans = 0;
  reps(i, n){
    ans += (a[i] * sum[i + 1]) % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
