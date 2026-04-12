#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
  }
  
  int ans=1;
  int x=H.at(0);
  
  for(int j=1;j<N;j++){
    x=max(x,H.at(j));
    if(x==H.at(j)){
      ans++;
    }
  }
  
  cout << ans << endl;
  
}