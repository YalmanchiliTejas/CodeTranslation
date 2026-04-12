#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n, m, a;
  while(1){
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    int t[n+m];
    int ans = 0, sum = 0;
    for(int i = 0 ; i < n ; i++){
      cin >> a;
      t[i] = a;
    }
    for(int i = 0 ; i < m ; i++){
      cin >> a;
      t[i+n] = a;
    }
    sort(t, t+n+m-1);
    
    for(int i = n + m - 1 ; i >= 0 ; i--){
      //cout << t[i]<< endl;
      if(i != 0) sum = t[i] - t[i-1];
      else sum = t[i];
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
  return 0;
}