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
int sub(int a,vector<char>b,int c,int d){
  if(c%2019==0&&c!=0)return 1;
  return sub(a+1,b,c+b[d]*a,d+1);
}
int main(){ 
  long long int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
  if(c*2<=a+b){
    if(max(d,e)==d){
      if(c*2>=a)cout<<c*2*e + a*(d-e);
      else cout<<c*2*d;
    }
    else {
      if(c*2>=b)cout<<c*2*d+b*(e-d);
      else cout<<c*2*e;
    }
  }
  else cout<<a*d+b*e;
}
