#include <algorithm>
#include <cstdint>
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

using namespace std;

using lint=int64_t;
using uint=uint32_t;
using ulint=uint64_t;

template<class T>
using vector2d=vector<vector<T>>;

template<class T>
bool UpdateMax(T &a, const T &b){
  if(a<b){
    a=b;
    return true;
  }else{
    return false;
  }
}

template<class T>
bool UpdateMin(T &a, const T &b){
  if(a>b){
    a=b;
    return true;
  }else{
    return false;
  }
}

template <class T>
void OutVec(const vector<T>& vec){
  for(int i = 0; i < vec.size() - 1; ++i){
    cout<<vec[i]<<" ";
  }
  cout<<vec.back()<<endl;
}

template <class T>
void OutVec2d(const vector2d<T>& vec){
  for(auto v:vec){
    OutVec(v);
  }
}

int main(){
  cout << std::fixed << std::setprecision(16);
  cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n;
  cin>>n;
  vector<lint> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  const lint INF=INT64_MIN/2;
  vector2d<lint> dp(n,vector<lint>(3,INF));
  dp[0][0]=a[0];
  dp[0][1]=0;
  dp[1][0]=INF;
  dp[1][1]=a[1];
  for(int i=2;i<n;i++){
    dp[i][0]=dp[i-2][0]==INF?INF:dp[i-2][0]+a[i];

    if(i==2){
      dp[i][1]=dp[i-2][1]+a[i];
    }else{
      dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i]);
    }

    if(i==2){
      dp[i][2]=a[2];
    }else if(i==3){
      dp[i][2]=max({dp[i-2][2]+a[i],dp[i-3][1]+a[i]});
    }else{
      dp[i][2]=max({dp[i-2][2]+a[i],dp[i-3][1]+a[i],dp[i-4][0]+a[i]});
    }

  }

  if(n%2==0){
    cout<<max({dp[n-2][0],dp[n-1][1]})<<endl;
  }else{
    cout<<max({dp[n-3][0],dp[n-2][1],dp[n-1][2]})<<endl;
  }

  return 0;
}


