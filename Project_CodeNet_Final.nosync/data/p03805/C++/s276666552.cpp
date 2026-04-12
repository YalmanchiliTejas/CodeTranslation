#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int a, b, N, M, ans = 0, sum;
  int glaph[8][8] = {};
  vector<int> p;
  cin >> N >> M;

  for(int i = 0;i < M;i++){
    cin >> a >> b;
    glaph[a-1][b-1] = 1;
    glaph[b-1][a-1] = 1;
  }

  for(int i = 1;i < N;i++){
    p.push_back(i);
  }

  do{
    sum = 0;
    sum += glaph[0][p[0]];
    for(int i = 0;i < N-2;i++){
      sum += glaph[p[i]][p[i+1]];
    }

    if(sum == N-1) ans++;
  } while(next_permutation(p.begin(), p.end()));

  cout << ans << endl;
  
  return 0;
}
