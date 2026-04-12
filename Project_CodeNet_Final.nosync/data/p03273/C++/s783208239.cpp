#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;

  char list[101][101];
  vector<int> anslist_i;
  vector<int> anslist_j;


  cin >>H>>W;

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >>list[i][j];
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(list[i][j] == '#'){
        anslist_i.push_back(i);
        break;
      }
    }
  }

  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(list[j][i] == '#'){
        anslist_j.push_back(i);
        break;
      }
    }
  }


  for(int i = 0; i < (int)anslist_i.size();i++){
    for(int j = 0;j < (int)anslist_j.size();j++){
      cout <<list[anslist_i[i]][anslist_j[j]];
    }
    cout <<'\n';
  }


  cout <<endl;
  return 0;
}
