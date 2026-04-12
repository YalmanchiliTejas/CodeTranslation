#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for(auto& x:h)
    cin >> x;
  int ans = 0;
  int highest = 0;
  for(auto& x:h){
    if(x >= highest){
      ans++;
      highest = x;
    }
  }
  cout << ans << endl;
}