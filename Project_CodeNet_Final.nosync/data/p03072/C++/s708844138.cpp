#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,H,Hmax=0,ans=0;
  cin >> N;
  for(int i=0; i<N; ++i){
    cin >> H;
    if(H >= Hmax){
      Hmax = H;
      ans++;
    }
  }
  cout << ans << endl;
}