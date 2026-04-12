#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using coord= pair<int, int>;

bool solve(const vector<string> &board, coord s, coord g){
  const char stone= '#';
  const int H= board.size();
  const int W= board.at(0).size();

  vector<int> rowN(H);
  vector<int> colN(W);
  for(int h=0; h<H; h++){
    for(int w=0; w<W; w++){
      if(board.at(h).at(w)==stone){
        rowN.at(h)++;
        colN.at(w)++;
      }
    }
  }

  vector<int> rowPick(H);
  vector<int> colPick(W);

  coord p= s;
  for(int h=0; h<H; h++){
    int w;
    tie(ignore, w)= p;
    if(board.at(h).at(w)==stone){
      rowPick.at(h)++;
      colPick.at(w)++;
    }
    
    while(w+1 < W && board.at(h).at(w+1)==stone){
      rowPick.at(h)++;
      colPick.at(w+1)++;
      w++;
    }

    p= make_pair(h+1, w);
  }

  bool ans= true;
  for(int h=0; h<H; h++){
    ans&= rowPick.at(h)==rowN.at(h);
  }
  for(int w=0; w<W; w++){
    ans&= colPick.at(w)==colN.at(w);
  }

  return ans;
}

int main(){
  int H,W;
  cin >> H >> W;

  coord s= make_pair(0, 0);
  coord g= make_pair(H-1, W-1);
  vector<string> board(H);
  for(int i=0; i<H; i++){
    cin >> board.at(i);
  }

  string ans= solve(board, s, g) ? "Possible"
                                 : "Impossible";

  cout << ans << endl;
}