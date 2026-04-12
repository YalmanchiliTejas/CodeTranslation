#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> data(H);

  for (int i = 0; i < H; i++)
  {
    cin >> data.at(i);
  }
  vector<bool> row(H,false);
  vector<bool> col(W,false);

  for(int i = 0 ; i < H ; i++ ){
    for(int j = 0 ; j < W ; j++ ){
      if(data[i][j] == '#'){
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  for(int i = 0 ; i < H ; i++ ){
    if(row.at(i) == true){
      for(int j = 0 ; j < W ; j++ ){
        if(col.at(j) == true){
          cout << data[i][j];
        }
      }
      cout << endl;
    }
  }

  return (0);
}
