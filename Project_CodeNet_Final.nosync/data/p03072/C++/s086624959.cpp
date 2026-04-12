#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, ans;
  cin >> N;
  int H[N];
  for(int i=0;i<N;i++) cin >> H[i];
  ans = 0;
  int maxi = H[0];
  for(int i=0;i<N;i++){
    if(maxi <= H[i]){
      maxi = H[i];
      ans++;
    }
  }
  cout << ans << endl;
}
