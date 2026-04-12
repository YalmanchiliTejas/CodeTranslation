#include <bits/stdc++.h>
using namespace std;

int H[101];
int ans = 0;
int main() {
	int N;
  cin >> N;
  for ( int i = 0; i < N; i++ )
  {
    cin >> H[i+1];
  }
  int max = H[1];
  for ( int i = 1; i <= N; i++ )
  {
    //cout << max << ":" << H[i] << endl;
    if ( max <= H[i] )
    {
      ans++;
      max = H[i];
    }
  }
  cout << ans << endl;
}