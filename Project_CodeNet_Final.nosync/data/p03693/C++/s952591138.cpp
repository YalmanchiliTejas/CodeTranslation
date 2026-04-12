#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
static const int giga = pow(10,9);

int main(void){
  int r,g,b;
  cin >> r >> g >> b;
  int ans = 100*r + 10*g + b;
  if(ans%4 == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}