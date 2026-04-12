#include<bits/stdc++.h>

using namespace std;

int main(){
   int H,W; //H tate W yoko 
   cin >> H >> W;
   vector<string> A(H); //[tate][yoko]
   for(int i=0;i<H;i++) cin >> A[i];
   int move = 0;
   for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
         if(A[i][j] == '#')move++;
      }
   }
   if(move == H+W-1)cout << "Possible" << endl;
   else cout << "Impossible" << endl;
   return 0;
}
