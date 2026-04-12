//g++ -std=gnu++14 a.cpp

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
//#include <ostream>


using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

int main(){
  string s;
  cin >> s;
  bool hantei = true;
  if(s.at(0)=='B'&&s.at(1)=='B'&&s.at(2)=='B')hantei=false;
  if(s.at(0)=='A'&&s.at(1)=='A'&&s.at(2)=='A')hantei=false;

  if(hantei){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }


}
