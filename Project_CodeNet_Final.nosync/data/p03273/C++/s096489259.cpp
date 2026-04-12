#include <bits/stdc++.h>

 using namespace std;

 int main() {
   int H, W;

   cin >> H >> W;

   vector<vector<char>> a(H, vector<char>(W));

   for (int i = 0; i < H; i++) {
     for (int j = 0; j < W; j++) {
       cin >> a.at(i).at(j);
     }
   }

   for (int i = 0; i < H; i++) {
     bool judge = true;
     for (int j = 0; j < W; j++) {
       if (a.at(i).at(j) == '#') {
         judge = false;
         break;
       }
     }
     if (judge) {
       for (int j = 0; j < W; j++) a.at(i).at(j) = 'D';
     }
   }

   for (int j = 0; j < W; j++) {
     bool judge = true;
     for (int i = 0; i < H; i++) {
       if (a.at(i).at(j) == '#') {
         judge = false;
         break;
       }
     }
     if (judge) {
       for (int i = 0; i < H; i++) a.at(i).at(j) = 'D';
     }
   }

   for (int i = 0; i < H; i++) {
     int counter = 0;
     for (int j = 0; j < W; j++) {
       if (a.at(i).at(j) != 'D') {
         cout << a.at(i).at(j);
         counter++;
       }
     }
     if (counter > 0) cout << endl;
   }
}
