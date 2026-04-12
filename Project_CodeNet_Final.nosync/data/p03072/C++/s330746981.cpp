#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  int ans = 0; int highest = 0;
  for(int i=0; i<N; i++){
    int H; cin >> H;
    if(H >= highest){
      highest = H; ans++;
    }
  }
  cout << ans << endl;
} 