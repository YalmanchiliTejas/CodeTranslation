#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  ll x,y;
  cin >> x >> y;

  ll ans_money = 0;

  ll tmp_ans_money = INF;
  
  if(a + b >= 2 * c) {

    tmp_ans_money = 0;

    while(x != 0 && y != 0) {
      ans_money += 2 * c;
      x--;
      y--;
    }

    //cout << ans_money << endl;

    tmp_ans_money = ans_money + x * 2 * c + y * 2 * c;
  }

  ans_money += x * a;
  ans_money += y * b;

  ans_money = min(ans_money, tmp_ans_money);

  cout << ans_money << endl;
}
