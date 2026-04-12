#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int m;
    int l;
 
   cin >> n >> m >> l;
  
   int ans = n/(m+l);
   int amari = n%(m+l);
  
//   cout << n << endl;
  // cout << m << endl;
  // cout << l << endl;
  // cout << ans << endl;
  // cout << amari << endl;
  
   if(amari>=l){
     
      cout << ans << endl;
     
   }else{
     
     cout << ans-1 << endl;
   }
  
  
  return 0;
}