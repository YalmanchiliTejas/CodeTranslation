#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,h,cnt=0,max=-1;
  cin >> n;
  vector<int> height(n);
  for(int i=0 ;i<n ;i++){
    cin >> h;
    height[i] = h;
  }
  for(int i : height){
    if(i >= max){
      cnt++;
      max = i;
    }
  }
  cout << cnt << endl; 
}