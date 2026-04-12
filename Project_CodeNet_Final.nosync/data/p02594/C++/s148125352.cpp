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
  int x;
  cin >> x;
  if(x >= 30){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
