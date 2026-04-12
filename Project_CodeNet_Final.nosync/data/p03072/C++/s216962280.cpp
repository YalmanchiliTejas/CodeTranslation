#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int v=0;
  int a,b,h;
  cin >> h;
  v++;
  for (int i=0; i<N-1; i++) {
    cin >> a;
    if (a>=h) {
      v++;
      h=a;
    }
  }
  cout << v << endl;
}
