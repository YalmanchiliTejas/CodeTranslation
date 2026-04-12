#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>


#define rep(i,n) for(int i = 0; i < (n); ++i)


using namespace std;

int main(void){
  int H,W;
  string str[16];
  cin >> H >> W;
  rep(i,H)cin >> str[i];
  rep(i,H)str[i] += '.';
  int h,w;
  h = 0;
  w = 0;


  while(1){
//     rep(i,H+1){
//       rep(j,W+1){
//         if(i == h && w == j){
//           cout << "X";
//         }else{
//           cout << str[i][j];
//         }
//       }
//       cout << endl;
//     }

    if(str[h][w] == '.'){
      cout << "Impossible" << endl;
      return 0;
    }

    str[h][w] = '.';

    if(h == H-1 && w == W-1){
      rep(i,H)rep(j,W){
        if(str[i][j] == '#'){
          cout << "Impossible" << endl;
          return 0;
        }
      }
      cout << "Possible" << endl;
      return 0;
    }
    
    if(str[h][w+1] == '#'){
      w++;
      continue;
    }
    if(str[h+1][w] == '#'){
      h++;
      continue;
    }
    break;
  }
  cout << "Impossible" << endl;
  return 0;
}
