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

lint Solve(vector<lint>& a, bool start_left){
  int left=0;
  int right=a.size()-1;
  bool should_put_left=start_left;
  vector<lint> sorted;
  if(a.size()%2==0){
    if(start_left){
      sorted.push_back(a[(a.size())/2]);
    }else{
      sorted.push_back(a[(a.size()/2-1)]);
    }
  }else{
    sorted.push_back(a[a.size()/2]);
  }

  while(sorted.size()<a.size()){
    if(should_put_left){
      sorted.push_back(a[left]);
      left++;
    }else{
      sorted.push_back(a[right]);
      right--;
    }
    should_put_left=!should_put_left;
  }
  lint result=0;
  for(int i=0;i<a.size()-1;i++){
    result+=abs(sorted[i+1]-sorted[i]);
  }
  return result;
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
  std::sort(a.begin(), a.end());
  cout<<max(Solve(a,true),Solve(a,false));

  return 0;
}


