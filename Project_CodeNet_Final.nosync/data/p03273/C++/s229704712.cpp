#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF=1001001001;

int main() {
  vector<vector<char>> data(110,vector<char>(110));
  int h,w;
  vector<bool> x(110,false);
  vector<bool> y(110,false);
  cin>>h>>w;
  rep(i,h){
  rep(j,w){
  cin>>data[i][j];
  }
  }
  rep(i,h){
  rep(j,w){
  if(data[i][j]=='#'){
  x[i]=true;
    y[j]=true;
  }
  }
  }
  rep(i,h){
  if(x[i]){
  rep(j,w) if(y[j])cout<<data[i][j];
    cout<<endl;
  }
  }
}