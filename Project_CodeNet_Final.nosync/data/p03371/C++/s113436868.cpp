#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  if(X < Y){
    ll tmp;

    tmp = X;
    X = Y;
    Y = tmp;
    tmp = A;
    A = B;
    B = tmp;
  }

  if(A + B <= 2*C){
    cout << X*A + Y*B << endl;
    return 0;
  }

  ll price = 0;

  price += 2*C*Y;
  X -= Y;

  if(A > 2*C){
    price += 2*C*X;
  } else{
    price += A*X;
  }

  cout << price << endl;
  
  return 0;
}
