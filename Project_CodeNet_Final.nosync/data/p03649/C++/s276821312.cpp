#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cfloat>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(){
  cout << std::fixed << std::setprecision(16);
  cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int64_t n;
  cin>>n;
  std::vector<int64_t> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }



  int64_t result=0;
  int64_t npow2=n*n;
  for(int i=0;i<n;i++){
    int64_t alpha=(a[i]/npow2);
    a[i]+=(-alpha*npow2+alpha*(n-1));
    for(int j=0;j<n;j++){
      if(i!=j){
        a[j]+=(alpha*(n-2));
      }
    }
    result+=alpha*(2*n-1);

  }

  while(true){
    bool found_greater=false;
    for(int i=0;i<n;i++){
      if(a[i]>=n){
        found_greater=true;
        int64_t operation=a[i]/n;
        a[i]%=n;
        result+=operation;
        for(int j=0;j<n;j++){
          if(i!=j){
            a[j]+=operation;
          }
        }
      }
    }
    if(!found_greater){
      break;
    }
  }
  cout<<result<<endl;


  return 0;
}