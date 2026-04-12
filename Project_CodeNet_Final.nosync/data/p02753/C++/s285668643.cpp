#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
int main() {
  string S ;
  cin >> S ;
  if(S[0] != S[1] || S[1] != S[2] )cout << "Yes" << endl;
  else cout << "No" << endl;
}