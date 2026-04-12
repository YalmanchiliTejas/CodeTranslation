#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//#のマスのみを通って、最短距離で左上から右下のマスに移動できるかを調べる
//常に右または下に動く時、最短距離で右下まで行ける　つまり#の個数が最短距離に一致
int main() {
 int H,W;
 cin >> H >> W;
 vector<vector<char>> maze(H, vector<char>(W));
 for(int i = 0;i<H;i++){
     for(int j = 0;j<W;j++){
         cin >> maze[i][j];
     }
 }
 int d = 0;//#の個数がH+W-1であれば最短移動している
 for(int i = 0;i<H;i++){
     for(int j = 0;j<W;j++){
         if(maze[i][j] == '#') d++;
     }
 }

if(d == H+W-1) cout << "Possible" <<endl;
else cout << "Impossible" <<endl;
 
}