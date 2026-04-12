#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF = 1<<30;

int main(){
  int h, w;cin>>h>>w;
  vector<vector<char>> field(h, vector<char>(w));
  vector<bool> row(h), column(w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>field[i][j];
    }
  }
  for(int i=0;i<h;i++){
    bool blank=true;
    for(int j=0;j<w;j++){
      if(field[i][j]=='#'){blank=false;break;}
    }
    if(blank)row[i]=true;
  }
  for(int i=0;i<w;i++){
    bool blank=true;
    for(int j=0;j<h;j++){
      if(field[j][i]=='#'){blank=false;break;}
    }
    if(blank)column[i]=true;
  }
  for(int i=0;i<h;i++){
    if(row[i])continue;
    for(int j=0;j<w;j++){
      if(column[j])continue;
      cout<<field[i][j];
    }
    cout << endl;
  }
}
