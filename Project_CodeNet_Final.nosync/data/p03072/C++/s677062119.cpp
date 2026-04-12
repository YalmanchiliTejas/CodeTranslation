#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int n;
  cin >> n;
  
  int ans = 0;
  int max_count = 0;
  
  for(int i = 0 ; i < n ; i++){
    int a;
    cin >> a;
    
    if(a >= max_count){
      ans++;
    }
    max_count = max(a,max_count);
  }
  
  cout << ans << endl;
}
    
    