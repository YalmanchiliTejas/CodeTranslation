#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> H;
  int Hi;
  for ( int i=0; i<N; i++ ) {
	cin >> Hi;
	H.push_back(Hi);
  }

  int ans = 0;
  int Hmax = 0;
  for ( int i=0; i<N; i++ ) {
	if ( H[i] >= Hmax ) {
	  Hmax = H[i];
	  ans++;
	};
  }

  cout << ans << endl;
  
  return 0;
}