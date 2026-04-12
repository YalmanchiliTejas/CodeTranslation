#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans=0;
  vector<int> h(20);
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> h.at(i);
  }
  int max_height = h.at(0);
  for(int i=0;i<n;i++){
    if(max_height<=h.at(i)){
      ans++;
      max_height=h.at(i);
    }
  }
  cout << ans << endl;
}
