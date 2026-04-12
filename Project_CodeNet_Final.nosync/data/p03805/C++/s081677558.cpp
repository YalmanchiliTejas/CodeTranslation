#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> edges;

bool is_all_visited(vector<bool> visited_list){
  for(int i=0;i<N;++i){
    if(!visited_list[i]){
      return false;
    }
  }
  return true;
}

int move(int current_point, vector<bool> visited_list, int count){
  visited_list[current_point-1] = true;
  if(is_all_visited(visited_list)){
    return count+1;
  }
  for(int i=0;i<M;++i){
    if(edges[i][0] == current_point && !visited_list[edges[i][1]-1]){
      count = move(edges[i][1], visited_list, count);
    }
    else if(edges[i][1] == current_point && !visited_list[edges[i][0]-1]){
      count = move(edges[i][0], visited_list, count);
    }
  }
  return count;
}


int main(void){
  cin >> N >> M;
  edges = vector<vector<int>>(M);
  vector<bool> visited_list = vector<bool>(N, false);
  for(int i=0;i < M;++i){
    edges[i] = vector<int>(2);
    cin >> edges[i][0] >> edges[i][1];
  }
  cout << move(1, visited_list, 0) << endl;
}
