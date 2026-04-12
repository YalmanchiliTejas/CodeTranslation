# include <bits/stdc++.h>

using namespace std;

# define rep(i, n) for(int i=0; i<(int)(n); i++)

vector<string> inputs(int H){
  vector<string> data(H);
  rep(i, H){
    cin >> data.at(i);
  }
  return data;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> data = inputs(H);
  
  vector<bool> row(H, false);
  vector<bool> column(W, false);
  rep(i, H){
    rep(j, W){
      if(data.at(i).at(j) == '#'){
        row.at(i) = true;
        column.at(j) = true;
      }
    }
  }
  rep(i, H){
    if(row.at(i)){
      rep(j, W){
        if(column.at(j))
          cout << data.at(i).at(j);
      }
      cout << endl;
    }
  }
}