#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int N, h, maxH = 0, ans = 0;
  cin >> N;
  
  for(int i = 0; i < N; i++) {
    cin >> h;
	if(h >= maxH) maxH = h, ans++;
  }
  cout << ans;
}

