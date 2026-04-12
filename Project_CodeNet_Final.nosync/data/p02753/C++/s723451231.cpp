//omajinai c++
#include <iostream>
#include<cmath>
#include<vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <type_traits>
#include <map>
#include <string>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define itn int
using ll = long long;
constexpr auto mod = 1000000007;
using namespace std;
int main() {
string s;
  cin>>s;
  if(s.find("AB")==-1&&s.find("BA")==-1){
    cout<<"No";
  }
  else{
    cout<<"Yes";
  }
}
