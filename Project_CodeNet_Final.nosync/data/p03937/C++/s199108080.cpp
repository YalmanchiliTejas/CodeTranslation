#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int H, W;
char board[8][15];
ii moves[2] = {ii(0, 1), ii(1, 0)};

int main(){
  int numHex = 0, numVisited = 1, r = 0, c = 0;
  scanf("%d %d", &H, &W);
  for(int i=0; i<H; i++) scanf("%s", board[i]);
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++) numHex+=board[i][j]=='#';
  while(r<H-1 || c<W-1){
    bool canMove = false;
    for(int i=0; i<2; i++){
      int r2 = r+moves[i].first, c2 = c+moves[i].second;
      if(r2>=H || c2>=W || board[r2][c2]!='#') continue;
      r = r2; c = c2; numVisited++; canMove = true; break;
    }
    if(!canMove) break;
  }
  printf(numVisited==numHex? "Possible\n": "Impossible\n");
  return 0;
}
