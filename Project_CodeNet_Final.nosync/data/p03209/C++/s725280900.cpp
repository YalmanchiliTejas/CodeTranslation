#include <iostream>
#include <vector>
using namespace std;

vector<long> tp(55);

long f(int n, long x) {
  if ( n==0 && x==0 )
    return 1;

  int sum = 0;
  int res = 0;
  if ( x == 0 )
    return 0;
  if ( x < tp[n+1]-2 )
    return f(n-1, x-1);
  if ( x == tp[n+1]-2 )
    return (tp[n]-1)+1;
  if ( x < tp[n+2]-4 )
    return (tp[n]-1)+1+f(n-1, x-(tp[n+1]-1));
  //  if ( x == tp[nn+2]-4 )
  return tp[n+1]-1;
}

int main() {
  int N;
  long X;
  cin >> N >> X;
  --X;
  
  tp[0] = 1;
  for ( int i=1; i<55; i++ ) {
    tp[i] = tp[i-1]*2;
  }
  cout << f(N, X) << endl;
  return 0;
}
