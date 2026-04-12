#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >>W;

vector<vector<char>> data(H, vector<char>(W));

for (int i = 0; i<H; i++){
  for (int j = 0; j<W; j++){
    cin >> data.at(i).at(j);
  }
}
vector<bool> white_H(H,false),white_W(W,false);
for(int i=0; i<H; i++){
  for(int j=0; j<W; j++){
   if(data.at(i).at(j) == '#'){
     white_H.at(i) = true;
     white_W.at(j) = true;
   }
  }
 }

for(int i=0; i<H; i++){
  if(white_H.at(i)){
    for(int j=0; j<W; j++){
      if(white_W.at(j)){
        cout << data.at(i).at(j);
      }
    }
    cout << endl;
  }
}
return 0;
}