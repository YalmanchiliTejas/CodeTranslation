#include <iostream>
#include <vector>
using namespace std;

int N;
int s[101010];

// 左から順に辿り着く座標
// 0, A, A-B, 2A-B, 2A-2B, 3A-2B, 3A-3B, 4A-3B ...
// C = A - Bとすると
// 0, A, C, A + C, 2C, 2C + A, 3C, ...
// xC + AがN-1になる必要がある。-> A, A+C, ... はN-1 - C, N-1 - 2C ...と書ける。
// xとCを決め打ちしたときに正数AとB(A > B)が定まればよい。

int main(){
  cin >> N;
  for(int i=0; i < N; ++i) cin >> s[i];
  
  long ans = 0;
  for(int C = 1; C < N; ++C) {
    long sum = 0;
    vector<bool> used(N);
    for(int x = 0; x * C < N; ++x) {
      long A = N-1 - x * C;
      long B = A - C;
      if(A <= 0 || B <= 0 || A < B) break;
      
      if(used[x * C]) break;
      sum += s[x * C];
      used[x * C] = true;
      
      if(used[N-1 - x * C]) break;
      sum += s[N-1 - x * C];
      used[N-1 - x * C] = true;
      
      ans = max(ans, sum);
    }
  }
  
  cout << ans << endl;
}