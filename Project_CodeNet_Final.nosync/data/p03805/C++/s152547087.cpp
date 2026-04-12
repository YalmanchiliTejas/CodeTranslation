/*
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
0 2
1 6
2 0 3
3 2 4 5
4 3 5
5 3 4 6
6 1 5
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//One-Stroke Path
int main(){
  int N, M;
  cin >> N >> M;
  //道の入力
  vector<pair<int, int>> p;
  for(int i = 0; i < M; i++){
    int fst, sec;
    cin >> fst >> sec;
    fst --;
    sec --;
    p.push_back(make_pair(fst, sec));
  }
  //道をあるノードから伸びてるかどうかで多重配列
  vector<vector<int>> path;
  for(int i = 0; i < N; i++){
    //配列を作って道があるか回してから突っ込む
    vector<int> dest;
    for(int j = 0; j < M; j++){
      if(p[j].first == i){
        dest.push_back(p[j].second);
      }
      else if(p[j].second == i){
        dest.push_back(p[j].first);
      }
    }
    path.push_back(dest);
  }
  //並び替えるノードの配列を作る
  vector<int> dot;
  for(int i = 1; i < N; i++){
    dot.push_back(i);
  }
  //何個通路あるか
  int count = 0;
  do{
    dot.insert(dot.begin(), 0);
    //dotの何番目の数を参照してるか
    for(int i = 0; i < N-1; i++){
      //次の数があるかどうか
      bool ok = false;
      //参照してるdotの数のpathの配列の中に次の数があるか
      int num = dot[i];
      for(int j = 0; j < path[num].size(); j++){
        if(path[num][j] == dot[i+1]){
          ok = true;
          break;
        }
      }
      if(!ok){
        break;
      }
      if(i == N-2){
        count ++;
      }
    }
    dot.erase(dot.begin());
  }while(next_permutation(dot.begin(), dot.end()));
  cout << count <<endl;
}