#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int A[9][9];


int main(void) {
  int n,m;
  cin >> n >> m;
  rep(i,9)rep(j,9){
    A[i][j] = 0;
  }
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    A[a-1][b-1] = 1;
    A[b-1][a-1] = 1;
  }
  vector<int> ord(n);
  rep(i,n) ord[i] = i;
  int cnt = 0;
  do{
    if(ord[0] !=  0) break;
    bool ok = true;
    rep(i,n-1){
      if(A[ord[i]][ord[i+1]] == 0) ok = false;
    }
    if(ok) cnt++;
  }while(next_permutation(ord.begin(),ord.end()));
  cout << cnt << endl;
  
  
    
  
}
