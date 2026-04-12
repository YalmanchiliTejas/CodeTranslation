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
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  std::vector<int> max;
  max.push_back(a[0]);
  for(int i=1;i<n;i++){
    if(max.size()==1){
      if(max[0]<a[i]){
        max[0]=a[i];
      }else{
        max.push_back(a[i]);
      }
    }else{
      int left=-1;
      int right=max.size();
      while(right-left>1){
        int mid=left+(right-left)/2;
        if(max[mid]<a[i]){
          right=mid;
        }else{
          left=mid;
        }
      }
      int res=right;
      if(res==max.size()){
        max.push_back(a[i]);
      }else{
        max[res]=a[i];
      }
    }
  }

  cout<<max.size()<<endl;


  return 0;
}
