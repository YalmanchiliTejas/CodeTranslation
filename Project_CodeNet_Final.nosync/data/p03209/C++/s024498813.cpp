#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

ll mypow(ll x, ll n) { //x^nの計算
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
    }
    x *= x;
    n >>= 1;  // n を1bit 左にずらす
  }
  return res;
}

ll hantei(int N,ll X){
  if(N==0){
    if(X==1){
      return 1;
    }
    else{
      return -1;
    }
  }
  else{
    ll num=mypow(2,N+2)-3;
    if(X==1){
      return 0;
    }
    else if(X==num){
      return 2*(mypow(2,N)-1)+1;
    }
    else if(X==(num+1)/2){
      return mypow(2,N);
    }
    else if(X<(num+1)/2){
      return hantei(N-1,X-1);
    }
    else{
      return mypow(2,N)+hantei(N-1,X-(num+1)/2);
    }
  }
}

int main(){
  int N;
  cin >> N;
  ll X;
  cin >> X;
  cout << hantei(N,X) << endl;
}