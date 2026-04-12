#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define srt(i) sort(i.begin(), i.end())
#define rvt(i) sort(i.begin(), i.end(), greater<int>())

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char> > table(h+1, vector<char>(w+1, ' '));

  for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++){
      cin >> table.at(i).at(j);
    }
  }

  for(int i=1; i<=h; i++){
    bool isBlank=true;
    for(int j=1; j<=w; j++){
      if(table.at(i).at(j) == '#') isBlank=false;
    }

    if(isBlank){
         for(int j=1; j<=w; j++){
          table.at(i).at(j) = ' ';
        }
    }
  }

  for(int j=1; j<=w; j++){
    bool isBlank=true;
    for(int i=1; i<=h; i++){
      if(table.at(i).at(j) == '#') isBlank=false;
    }

    if(isBlank){
         for(int i=1; i<=h; i++){
          table.at(i).at(j) = ' ';
        }
    }
  }

  for(int i=1; i<=h; i++){
    bool isBlank=true;
    for(int j=1; j<=w; j++){
      if(table.at(i).at(j) != ' ') {
        cout << table.at(i).at(j); 
        isBlank = false;
      }
    }
    if(!isBlank) cout << endl;
  }

}