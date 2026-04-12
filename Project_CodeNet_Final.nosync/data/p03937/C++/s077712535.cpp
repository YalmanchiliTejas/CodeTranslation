#include <bits/stdc++.h>
using namespace std;

bool solve(int h, int w, vector<string> &v){
  if(h != 0 && w != 0){
    if((v[h][w - 1] == '#' && v[h - 1][w] != '#') || (v[h][w - 1] != '#' && v[h - 1][w] == '#')){
      if(h == v.size() - 1 && w == v[0].size() - 1){
        return true;
      }
    }else{
      return false;
    }
  }

  if(v.size() - 1 == h && v[h][w + 1] == '#'){
    return solve(h, w + 1, v);
  }else if(v.size() - 1 == h && v[h][w + 1] != '#'){
    return false;
  }else if(v[0].size() - 1 == w && v[h + 1][w] == '#'){
    return solve(h + 1, w, v);
  }else if(v[0].size() - 1 == w && v[h + 1][w] != '#'){
    return false;
  }else if(v[h + 1][w] == '#' && v[h][w + 1] == '.'){
    return solve(h + 1, w, v);
  }else if(v[h][w + 1] == '#' && v[h + 1][w] == '.'){
    return solve(h, w + 1, v);
  }else{
    return false;
  }

}

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  for(int i = 0;i < h;i++){
    cin >> v[i];
  }
  /*for(auto i: v){
    cout << i << endl;
  }*/
  if(solve(0, 0, v)){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
}
