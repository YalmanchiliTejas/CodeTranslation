#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int ans = 0;
  int preH = 0;
  for (int i = 0; i < N; i++) {
    int H;
    cin >> H;
    if (preH <= H) {
      ans++;
    }
    preH = max(preH, H);
  }
  cout << ans << endl;
  return 0;
}
