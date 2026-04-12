# include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main(){

  int N;
  cin >> N;
  int H[N];
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
  int ans = 0;
  int ref = 0;
  for(int i = 0; i < N; i++){
    if(H[i] >= ref){
      ans++;
    }
    ref = max(ref, H[i]);
  }

  cout << ans << endl;

}
