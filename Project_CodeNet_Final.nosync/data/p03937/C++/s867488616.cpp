#include <bits/stdc++.h>

using namespace std;

string a[10];
int h, w;

bool check(){
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#')return false;
    }
  }
  return true;
}

bool dfs(int y, int x){
  if(y==0 && x==0)return check();
  if(y>0 && a[y-1][x]=='#'){
    a[y-1][x] = '.';
    bool tmp = dfs(y-1, x);
    if(tmp)return true;
    a[y-1][x] = '#';
  }
  if(x>0 && a[y][x-1]=='#'){
    a[y][x-1] = '.';
    bool tmp = dfs(y, x-1);
    if(tmp)return true;
    a[y][x-1] = '#';
  }
  return false;
}

int main(){
  cin >> h >> w;
  for(int i=0;i<h;i++){
    cin >> a[i];
  }
  if(a[h-1][w-1]=='.'){
    cout << "Impossible" << endl;
  }
  a[h-1][w-1] = '.';
  cout << (dfs(h-1, w-1)?"Possible": "Impossible") << endl;
}

