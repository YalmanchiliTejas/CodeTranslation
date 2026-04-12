#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> data(N, vector<int> (N));
  int a, b, ans = 0;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    a--;
    b--;
    data.at(a).at(b) = 1;
    data.at(b).at(a) = 1;
  }
  int flag;
  vector<int> sub(N);
  for(int i = 0; i < N; i++)sub.at(i) = i;
  do {
    flag = 1;
    for(int i = 0; i < N - 1; i++){
      if(data.at(sub.at(i)).at(sub.at(i + 1)) == 0){
        flag = 0;
        break;
      }
    }
    if(flag == 1)ans++;
  } while(next_permutation(sub.begin() + 1, sub.end()));
  cout << ans << endl;
  return 0;
}