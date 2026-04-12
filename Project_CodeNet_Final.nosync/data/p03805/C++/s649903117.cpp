#include <bits/stdc++.h>
using namespace std;

void move(int start, vector<vector<int>> route, vector<bool> flag, int &count){
  flag.at(start) = true;
  bool con = false;
  for (int i = 1; i < flag.size(); i++){
    if (flag.at(i) == false)
      con = true;
  }
  if (con == false)
    count++;
  
  for (int i : route.at(start)){
    if (flag.at(i) == false)
      move(i, route, flag, count);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> route(N + 1, vector<int>(0));
  for (int i= 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    route.at(a).push_back(b);
    route.at(b).push_back(a);
  }
  vector<bool> flag(N + 1, false);
  int count = 0;
  move(1, route, flag, count);
  cout << count << endl;
}