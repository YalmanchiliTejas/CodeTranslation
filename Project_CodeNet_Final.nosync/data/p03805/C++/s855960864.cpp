#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> G(N, vector<bool>(N, false));
  rep(i, M){
    int a, b;
    cin >> a >> b;
    G.at(a-1).at(b-1) = true;
    G.at(b-1).at(a-1) = true;
  }
  
  vector<int> vec(N);
  rep(i, N) vec.at(i) = i;
  int ans = 0;
  do { 
    bool flag = true;
    for(int i = 0; i < N - 1 ; i++){
      if (!G.at(vec.at(i)).at(vec.at(i+1))){
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  } while (next_permutation(vec.begin()+1, vec.end()));
  cout << ans << endl;
}
