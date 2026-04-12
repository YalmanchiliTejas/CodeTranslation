#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<string>
#include<cmath>
#include<tuple>
#define INF 1111111
using namespace std;
typedef pair<int,int> P;
typedef tuple<int,int,int> tup;
typedef long long ll;

int main() {
  int h,w;
  cin >> h >> w;
  char map[110][110] = {};
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin >> map[i][j];
  int erase[110][110] = {};
  
  for(int i=0;i<h;i++){
    bool flag = true;
    for(int j=0;j<w;j++){
      if(map[i][j] == '#')
        flag = false;
    }
    if(flag){
      for(int j=0;j<w;j++)
        erase[i][j] = 1;
    }
  }
  
  for(int j=0;j<w;j++){
    bool flag = true;
    for(int i=0;i<h;i++){
      if(map[i][j] == '#')
        flag = false;
    }
    if(flag){
      for(int i=0;i<h;i++)
        erase[i][j] = 1;
    }
  }
  
   for(int i=0;i<h;i++){
      bool flag = false;
    for(int j=0;j<w;j++){
      if(erase[i][j] == 0){
      cout << map[i][j];
      flag = true;
      }
    }
     if(flag)
     cout << endl;
   }
}