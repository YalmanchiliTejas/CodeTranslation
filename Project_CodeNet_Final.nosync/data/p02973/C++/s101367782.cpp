#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>

#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())

#define eb emplace_back
#define pf push_front
#define dbg(x) cout<<#x" = "<<((x))<<endl
#define fs first
#define sc second
     
using namespace std;
     
     
typedef long long ll;
typedef pair<ll, ll> P;
     
     
int main(){
  ll N;

  cin >> N;

#ifdef DEBUG
  cout << "N=" << N << endl;
#endif

  vector<int> colorToVal;
  for(int i = 0; i < N; ++i){
    int tmp;
    cin >> tmp;
    
    auto itr = lower_bound(colorToVal.begin(), colorToVal.end(), tmp);
    if(itr == colorToVal.begin()) {
      colorToVal.insert(colorToVal.begin(), tmp);
    } else {
      itr--;
      *itr = tmp;
    }
  }

  cout << colorToVal.size() << endl;
  
  return 0;
}
