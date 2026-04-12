//
// Created by moono on 2019/01/31.
//

#include <string.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

bool is_all_arrived(vector<bool> bools){
  for(bool b: bools){
    if(!b) return false;
  }
  return true;
}



int main() {
  //
  int N, M;
  cin >> N >> M;


  //
  vector<int> graph[N];
  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    graph[--from].push_back(--to);
    graph[to].push_back(from);
  }

  //
  vector<bool> *is_arrive = new vector<bool>(N);
  fill(is_arrive->begin(), is_arrive->end(), false);
  queue<pair<int, vector<bool>*>> Q({make_pair(0, is_arrive)});

  //
  int num = 0;
  while(!Q.empty()){
    auto pair = Q.front(); Q.pop();
    int position = pair.first;
    vector<bool> is_arrive = *pair.second;

    //
    is_arrive[position] = true;
    if(is_all_arrived(is_arrive)){
      num++;
    }else{
      vector<int> next_candidate = graph[position];
      for (int i : next_candidate) {
        if(!is_arrive[i]){
          vector<bool> *is_arrive2 = new vector<bool>(is_arrive);
          Q.push(make_pair(i, is_arrive2));
        }
      }
    }
  }

  cout << num << endl;

  return 0;
}