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

int main(void){
  int n;
  cin >> n;
  if(n == 3 || n == 5 || n == 7){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}