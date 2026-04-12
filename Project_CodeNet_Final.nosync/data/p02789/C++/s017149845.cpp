#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m; cin >> n >> m;

  bool flag = false;
  if(n==m) flag = true;

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
    
  return 0;
}
