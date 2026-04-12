#include <bits/stdc++.h>

 using namespace std;

 int main() {
   int H, W;
   cin >> H >> W;

   vector<vector<char>> A(H + 1, vector<char>(W + 1));
   int count = 0;
   for (int i = 1; i <= H; i++) {
     for (int j = 1; j <= W; j++) {
       cin >> A.at(i).at(j);
       if (A.at(i).at(j) == '#') count++;
     }
   }
   if (count == H + W - 1) cout << "Possible" << endl;
   else cout << "Impossible" << endl;
}
