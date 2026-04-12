#include<iostream>
#include<cmath>
using namespace std;

int main() {
   int H, W;
   cin >> H >> W;

   char temp[H][W];
   bool bh[H], bw[W];

   for (int h = 0; h < H; h++) {
      for (int w = 0; w < W; w++) {
         cin >> temp[h][w];
      }
   }
   
   for (int h = 0; h < H; h++) {
      bh[h] = false;
      for (int w = 0; w < W; w++) {
         if (temp[h][w] == '#') bh[h] = true;
      }
   }
   for (int w = 0; w < W; w++) {
      bw[w] = false;
      for (int h = 0; h < H; h++) {
         if (temp[h][w] == '#') bw[w] = true;
      }
   }

   for (int h = 0; h < H; h++) {
      if (bh[h] == true) {
         for (int w = 0; w < W; w++) {
            if (bw[w] == true) cout << temp[h][w];
         }
         cout << endl;
      }
   }

   return 0;
}
