#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
using namespace std;

typedef long long ll;

ll p[55],a[55];

ll func(int N,ll X) {
  if ( N == 0 && X <= 0 ) return 0;
  else if ( N == 0 && X > 0 ) return 1;
  else if ( X <= 1+a[N-1] ) return func(N-1,X-1);
  else if ( X == 2+a[N-1] ) return p[N-1]+1;
  else if ( X <= 2+2*a[N-1] ) return p[N-1]+1+func(N-1,X-2-a[N-1]);
  else return 2*p[N-1]+1;
}

int main() {
  int N; ll X; cin >> N >> X;
  p[0] = 1;
  a[0] = 1;
  for ( int i = 1; i <= N; i++ ) {
    p[i] = p[i-1] * 2 + 1;
  }

  for ( int i = 1; i <= N; i++ ) {
    a[i] = a[i-1] * 2 + 3;
  }

  cout << func(N,X) << endl;
  return 0;
}
