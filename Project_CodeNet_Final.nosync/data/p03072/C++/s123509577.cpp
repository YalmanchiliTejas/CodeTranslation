#include <bits/stdc++.h>
using namespace std;
int main() {
     int N;
     cin >> N;
     vector<int> H(N);
     for(int i=0;i < N;i++){
          cin >> H[i];
     }

     int ans = 0;
     int x = 0;
     for(int i=0;i < N;i++){
          if(x <= H[i]) ans++;
          x = max(x,H[i]);
     }

     cout << ans << endl;
}