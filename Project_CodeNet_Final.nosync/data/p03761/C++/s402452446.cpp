#include<iostream>
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
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
#define ll  long long 
  vector<ll>dp(100000);
  vector<vector<ll>>e(100000,vector<ll>(0));
int main(){
  ll a,d;cin>>a;
  string c;
  vector<map<char,ll>>b(a);
  rep(i,a){
    cin>>c;
    rep(o,c.size()){
      if(b[i].count(c[o]))b[i][c[o]]++;
      else b[i][c[o]]=1;
    }
}
for(char i='a';i<='z';i++){
  d=INT_MAX;
  rep(o,a){
    if(b[o].count(i))d=min(d,b[o][i]);
    else {
      d=0;
      break;
    }
  }
  rep(o,d)cout<<i;
}
  }
