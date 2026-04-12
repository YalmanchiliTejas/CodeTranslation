#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int h,w;
  cin >> h >> w;
  vector<vector<char>> x(h, vector<char>(w));
  vector<vector<char>> y(w, vector<char>(h));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      char tmp;
      cin >> tmp;
      x.at(i).at(j) = tmp;
      y.at(j).at(i) = tmp;
    }
  }
  string X="";
  string Y="";
  for(int i= 0; i < h; i++){
    X+=".";
  }
  for(int j= 0; j < w; j++){
    Y+=".";
  }

  map<int,bool> mx,my;
  for(int i = 0; i < h; i++){
    string tmp = "";
    for(int j = 0; j < w; j++){
      tmp += x.at(i).at(j);
    }
    if(tmp == Y){
      mx[i] = true;
    }
  }
  for(int j = 0; j < w; j++){
    string tmp = "";
    for(int i = 0; i < h; i++){
      tmp += y.at(j).at(i);
    }
    if(tmp == X){
      my[j] = true;
    }
  }

  for(int i = 0; i < h; i++){
    if(mx.count(i) != 0) continue;
    for(int j = 0; j < w; j++){
      if(my.count(j) != 0) continue;
      cout << x.at(i).at(j);
    }
    cout << endl;
  }
}
