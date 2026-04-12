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
   int ans = n*100+m*10+l;
   
  
  if (ans%4==0){
    
     cout << "YES" << endl;
    
  }else{
    
     cout << "NO" << endl;
    
  }

  
  return 0;
}