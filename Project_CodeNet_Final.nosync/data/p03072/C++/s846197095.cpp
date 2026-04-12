#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i=0;i<N;i++){
    cin >> H[i];
  }
  
  int ans=0;
  int maxh=H[0];
  
  for (int i=1;i<N;i++){
      if(H[i] >= maxh){
        maxh = H[i];
        ans += 1;
    }
  }
  
  cout << ans + 1 <<endl;
  
}