#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N; cin >> N;
  vector<int> H(N);
  
  for(int i = 0; i < N; i++){
    cin >> H[i];
  }
  
  int cnt = 1;
  bool judge = true;
  
  for(int i = 1; i < N; i++){
   for(int j = i-1 ; j >= 0; j--){
     if(H[i] >= H[j]){
     }
     else if(H[i] < H[j]){
       judge = false;
       break;
     }
   }
   if(judge){
       cnt++;
   }
   judge = true;
  }
  
  cout << cnt << endl;
    
  return 0;
}