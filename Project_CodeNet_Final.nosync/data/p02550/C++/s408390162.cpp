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

int main(){
  ll N,X,M;
  cin >> N >> X >> M;
  vector<int> amari(M,0);
  ll test=X%M;
  ll start=-1,finish=-1;
  for(ll i=1;i<=N;i++){
    if(amari[test%M]!=0){
      start=amari[test%M];
      finish=i-1;
      break;
    }
    else{
      amari[test%M]=i;
    }
    test=test*test%M;
  }
  ll ans=0;
  test=X%M;
  if(finish==-1){
    for(ll i=1;i<=N;i++){
      ans+=test;
      test=test*test%M;
    }
    cout << ans << endl;
    return 0;
  }
  test=X%M;
  for(int i=1;i<start;i++){
    test=(test*test)%M;
  }
  ll period=0;
  for(ll i=start;i<=finish;i++){
    period+=test;
    test=test*test%M;
  }
  ll syuki=finish-start+1;
  N=N-(start-1);
  ll kaisuu=N/syuki;
  N=N-syuki*kaisuu;
  ans+=kaisuu*period;
  test=X%M;
  for(ll i=1;i<start;i++){
    ans+=test;
    test=test*test%M;
  }
  test=X%M;
  for(int i=1;i<start;i++){
    test=(test*test)%M;
  }
  for(ll i=1;i<=N;i++){
    ans+=test;
    test=test*test%M;
  }
  cout << ans << endl;
}