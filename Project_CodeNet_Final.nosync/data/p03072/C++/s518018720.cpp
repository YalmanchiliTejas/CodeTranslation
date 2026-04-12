#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  
  for(int i = 0; i < n; i++){
  	cin >> h.at(i);
  }
  
  int maximum = 0;
  int ans = 0;
  
  for(int i = 0; i < n; i++){
  	if(h.at(i) >= maximum) {
    	maximum = h.at(i);
    	ans++;
    }
  }
  cout << ans << endl;
}