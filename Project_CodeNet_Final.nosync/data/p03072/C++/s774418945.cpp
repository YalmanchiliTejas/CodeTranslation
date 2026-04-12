#include <iostream> 
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <fstream>
using namespace std;
#define ll long long int


int main( ) {
  int n,ans = 1;
  cin >> n;
  vector <int> h(n);
  for ( int i = 0; i < n; ++i ) {
    cin >> h[i];  
  }
  int M = h[0];
  for ( int i = 0; i < n; ++i ) {
    if (i == 0 ) continue;
    if( M <= h[i] ){
      M = h[i];
      ans++;
    }  
  }
  cout << ans << endl;
  return 0;
}
