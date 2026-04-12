#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int N, INF = 1e9;
  cin >> N;
  int m = INF, M = 0, bigger_m = INF, smaller_M = 0, x, y;
  priority_queue< pair<int,int> > smaller;
  vector<int> X(N), Y(N);
  for(int i = 0; i < N; ++i){
    cin >> x >> y;
    if(x > y) swap(x,y);
    m = min(m,x);
    M = max(M,y);
    bigger_m = min(bigger_m,y);
    smaller_M = max(smaller_M,x);
    smaller.emplace(-x, i);
    X[i] = x;
    Y[i] = y;
  }
  long long int ans = (long long int)(M - bigger_m)*(smaller_M - m);
  for(int i = 0; i < N; ++i){
    pair<int,int> p = smaller.top();
    int x = -p.first, k = p.second;
    smaller.pop();
    if(Y[k] < x) {
      printf("break: Y[k] = %d, x = %d\n", Y[k], x);
      break;
    }
    smaller.emplace(-Y[k],k);
    smaller_M = max(Y[k], smaller_M);
    bigger_m = -smaller.top().first;
    ans = min(ans,(long long int)(M-m)*(smaller_M-bigger_m));
  }
  cout << ans << endl;
  return 0;
}
