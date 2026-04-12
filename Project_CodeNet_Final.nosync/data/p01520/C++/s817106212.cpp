#include <iostream>
#include <algorithm>

using namespace std;

bool check(int t, int e, int d){
  int tmp = t / d;
  if(abs(d * tmp - t) <= e) return true;
  if(abs(d * (tmp + 1) - t) <= e) return true;
  return false;
}

main(){
  int n, t, e;
  cin >> n >> t >> e;
  int ans = -1;
  for(int i=0;i<n;i++){
    int in;
    cin >> in;
    if(check(t, e, in)){
      ans = i+1;
    }
  }
  cout << ans << endl;
}