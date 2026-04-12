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

  string s;
  cin>>s;
  int k;
  cin>>k;

  int dp[101][2][4]={};
  dp[0][0][1]=1;
  dp[0][1][1]=s[0]-'0'-1;
  dp[0][1][0]=1;

  for(int i=1;i<s.size();i++){
    for(int c=0;c<=3;c++){
      dp[i][1][c]=dp[i-1][1][c];
      if(s[i]!='0'){
        dp[i][1][c]+=dp[i-1][0][c];
      }
      if(c>0){
        dp[i][1][c]+=dp[i-1][1][c-1]*9;
        if(s[i]!='0'){
          dp[i][1][c]+=dp[i-1][0][c-1]*(s[i]-'0'-1);
        }
      }
      if(s[i]=='0'){
        dp[i][0][c]=dp[i-1][0][c];
      }else{
        if(c>0){
          dp[i][0][c]=dp[i-1][0][c-1];
        }
      }

    }


  }

  cout<<dp[s.size()-1][0][k]+dp[s.size()-1][1][k]<<endl;

  return 0;
}


