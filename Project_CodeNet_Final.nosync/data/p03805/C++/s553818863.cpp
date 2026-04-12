#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// if i and j is connected
bool connected[10][10];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, M; cin >> N >> M;
  for(int i=0;i<M;i++){
    int a, b; cin >> a >> b;
    connected[a][b] = true;
    connected[b][a] = true;
  }
  int p[N-1];
  int cnt = 0;
  for(int i=0;i<N-1;i++) p[i] = i+2;
  do{
    int prev = 1;
    bool flag = true;
    for(int i=0;i<N-1;i++){
      if(!connected[prev][p[i]]){
        flag = false;
        break;
      }
      prev = p[i];
    }
    if(flag) cnt++;
  }while(next_permutation(p, p+(N-1)));
  cout << cnt << endl;
}