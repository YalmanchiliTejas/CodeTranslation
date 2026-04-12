#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,max,ans;
  max = 0;
  ans = 0;
  cin >> N;
  int H[N];
  for(int i=0;i<N;i++)
    cin >> H[i];
  for(int k=0;k<N;k++){
    if(H[k]>=max){
      ans++;
  	  max = H[k];
    }
  }
  cout << ans << endl;
}
