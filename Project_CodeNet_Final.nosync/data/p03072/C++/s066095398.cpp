#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  int n;
  cin >> n;
  
  int h[n];
  rep(i,n) cin >> h[i];
  
  int ans = 1;
  int flag = 0;
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(h[i] < h[j]){
        flag = 1;
      }//if
    }//for
    if(flag == 0){
      ans++;
    }
    flag = 0;
  }//for
  
  cout << ans << endl;
}