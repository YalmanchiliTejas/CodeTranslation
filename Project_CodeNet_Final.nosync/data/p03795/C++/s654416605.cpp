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
  int n;
  cin >> n;
  int x = 800*n;
  int y = (n/15)*200;
  cout << x-y << endl;

  return 0;
}