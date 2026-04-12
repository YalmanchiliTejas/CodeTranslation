#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  int cnt=0;
  for(int i=0;i<n;i++){
	cin >> h.at(i);
    if(i==0){
      cnt++;
      continue;
    }
    for(int j=0;j<i;j++){
      if(h.at(i) < h.at(j)){
        break;
      }else if(j==(i-1)){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
  
}