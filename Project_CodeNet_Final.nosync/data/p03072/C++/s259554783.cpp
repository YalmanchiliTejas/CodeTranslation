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

int main() {
  int N; cin >> N;
  int H[101];
  for ( int i = 0 ; i < N; i++ )  cin >> H[i];
  int cnt = 1;

  for ( int i = N-1; i > 0; i-- ) {
    bool f = true;
    int tmp = H[i];
    for ( int j = i-1; j >= 0 ; j-- ) {
      if ( tmp < H[j] ) f = false; 
    }
    if (f)cnt++;
  }

  cout << cnt << endl;
  return 0;
}
