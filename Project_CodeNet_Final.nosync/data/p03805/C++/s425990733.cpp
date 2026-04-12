#include <bits/stdc++.h>
using namespace std;
#define rep0(i, a) for(int i=0;i < (int)(a); i++)
#define rep(i, a, b) for(int i=(a);i < (b); i++)

int main(){
  int N, M, i,j, a, b;
  cin >> N >> M;
  vector<vector<int>> to(N+1, vector<int>(N+1, 0));
  rep0(i, M){
    cin >> a >> b;
    to[a][b] = 1;
    to[b][a] = 1;
  } 
  
  vector<int> arr(N);
  rep(i, 1, N+1){
    arr[i-1] = i;
  }
  int ret = 0;
  do{
    if (arr[0] != 1)continue;
    bool done = true;
    rep0(i, N-1){
      if (to[arr[i]][arr[i+1]] == 0){done = false;break;}
    }
    if (done)ret++;
  }while (next_permutation(arr.begin(), arr.end()));
  cout << ret << endl;

}