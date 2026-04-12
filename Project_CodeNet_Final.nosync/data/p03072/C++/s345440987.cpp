#include<iostream>
using namespace std;

int main(){
  int ans = 1;
  int judge;
  int N;
  cin >> N;
  int H[N];
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      judge = 0;
      if(H[j]>H[i]){
        judge = 1;
        break;
    }
    }
      if(judge == 0){
        ans++;
      }
  }
        
  cout << ans << endl; 
  return 0;
}
      
