#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  for (int j = 0;j < 20; j++ ){
    int n; cin >> n;
    if (n == 0) {
      break;
    }
    int s[n]; for (int i = 0; i < n; i++) cin >> s[i];

    sort(s, s+n);int t = 0;
    for (int i = 1; i < n - 1; i++) {
      t += s[i]; 
    }
    cout << t / (n - 2) << endl;
  }
   return 0;
}
