#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll r, g, b;
  cin >> r >> g >> b;
  
  if ((10*g + b) % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
