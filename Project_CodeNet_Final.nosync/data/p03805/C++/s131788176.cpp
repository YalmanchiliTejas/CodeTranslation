#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N, M;
  cin >> N >> M;
  
  vector<vector<bool>> G(N, vector<bool>(N));
  int A, B;
  for( int i = 0; i < M; i++ ){
    cin >> A >> B;
    G.at(A-1).at(B-1) = true;
    G.at(B-1).at(A-1) = true;
  }
  
  vector<int> zyun(N-1);
  for( int i = 0; i < N-1; i++ ) zyun.at(i) = i+1;
    
  
  int ans = 0;
  bool hantei;
  do{
    hantei = true;
    if( G.at(0).at(zyun.at(0)) == false ) hantei = false;
    for( int i = 0; i < N-2; i++ ){
      if( G.at(zyun.at(i)).at(zyun.at(i+1)) == false ){
        hantei = false;
      }
    }
    if( hantei == true ) ans++;
  }while( next_permutation(zyun.begin(), zyun.end()) );
  
  cout << ans << endl;
 
  
}