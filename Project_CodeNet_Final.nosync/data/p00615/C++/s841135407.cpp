#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m;
  while(cin >> n >> m, n or m){
    vector<int> V(n+m+1);
    V[0] = 0;
    for(int i = 0; i < n+m; ++i) cin >> V[i+1];
    sort(V.begin(), V.end());
    int ans = 0;
    for(int i = 0; i < n+m; ++i) ans = max(ans, V[i+1]-V[i]);
    cout << ans << endl;
  }
}

