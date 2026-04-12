#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
 int N;
  cin>> N;
 
  vector<int> Hs(N);
  for(int i =0 ; i < N;i++){
    cin >> Hs.at(i) ;
  }
  
  int max = Hs.at(0);
  int ans = 1;
  if(N>1){
    for(int i = 1 ; i <N;i++){
    if(max <= Hs.at(i) ) {
      ans ++;
      max = Hs.at(i);

    }
  
    } 
 
    
 }
  
  cout << ans <<endl;
 return 0; 
}