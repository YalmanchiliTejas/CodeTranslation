#include <bits/stdc++.h>
using namespace std;

#define int long long

int N;
vector<char> P;

char f(char a, char b) {
  if ( a == 'T' && b == 'T' ) return 'T';
  if ( a == 'T' && b == 'F' ) return 'F';
  if ( a == 'F' && b == 'T' ) return 'T';
  if ( a == 'F' && b == 'F' ) return 'T';
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N;
  P = vector<char>(N);  
  for ( int i = 0; i < N; i++ ) {
    cin >> P[i];    
  }

  char c = P[0];  
  for ( int i = 1; i < N; i++ ) {
    c = f(c, P[i]);    
  }

  cout << c << endl;
  
  return 0;
}

