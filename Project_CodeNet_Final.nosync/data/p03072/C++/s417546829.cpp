#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> mts(N);
  int ans = 0;
  
  for(int k=0; k<N; k++){
    cin >> mts.at(k);
  }
  
  for(int i=0; i<N; i++){
    
    int a = 0;
    
    for(int j=0; j<i; j++){
      
      if(mts.at(i) < mts.at(j)){
        
        a++;
        
      }
      
    }
      
    if(a == 0){
      
      ans++;
      
    }
      
    }
      
  cout << ans << endl;
  
}
