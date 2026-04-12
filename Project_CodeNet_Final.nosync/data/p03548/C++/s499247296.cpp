#include <bits/stdc++.h>
#include <map>
 #define rep(i,n) for(int i=0;i<n;i++)
 using namespace std;
  int main(){
      int x,y,z;
      cin >> x >> y >> z;
      int ans = 0;
      ans = (x-(2*z))/(y+z);
     if((x-(2*z))%(y+z)==y){
         ans++;
     }      
     cout << ans << endl;
     return 0;
     
  }