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

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//INT_MAX	2,147,483,647 = 2*1.0e9

vector<ll> a;
vector<ll> p;

ll calc(int n, ll x){
  if(n == 0){
    if(x == 0) return 0;
    else return 1;
  } else {
    if(x == 1) return 0;
    if(1 < x && x <  2 + a[n-1]) return calc(n-1, x-1);
    if(x == 2 + a[n-1]) return p[n-1] + 1;
    if(2+a[n-1] < x && x < 3 + 2*a[n-1]) return p[n-1] + 1 + calc(n-1, x-2-a[n-1]);
    return p[n];
  }
}


int main(){
  int N; ll X;
  cin >> N >> X;

  a.resize(N+1);
  p.resize(N+1);

  a[0] = 1; p[0] = 1;
  for(int i = 0; i < N; i++){
    a[i+1] = 2 * a[i] + 3;
    p[i+1] = 2 * p[i] + 1;
  }

  cout << calc(N, X) << endl;
  
  return 0;
}
