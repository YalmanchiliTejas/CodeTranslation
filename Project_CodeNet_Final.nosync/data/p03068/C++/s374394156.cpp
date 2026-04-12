#include <iostream>
#include <iomanip>
// std::cout << std::setprecision(2) << 3.141; // "3.1"
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
// double pi = 3.141592653589793238463;

int main(void){
  string input;
  int n,k;
  cin >> n >> input >> k;
  char target = input[k-1];
  
  for(int i = 0; i < n; i++){
    if(input[i] == target){
      cout << input[i];
    } else {
      cout << '*';
    }
  }
  cout << endl;
  

  return 0;
}