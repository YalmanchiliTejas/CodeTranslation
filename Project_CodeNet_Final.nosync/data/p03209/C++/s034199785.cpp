#include<iostream>
using namespace std;
#define MAX 50
long a[MAX+1], p[MAX+1];

long f(int N, long X) {
  if (N == 0) {
    if (X <= 0) {
     return 0;
    } else return 1;
  } else if (X <= 1 + a[N-1]) {
    return f(N-1, X-1);
  } else if (X == 2 + a[N-1]) {
    // cout << "hoge" << endl;
    return p[N-1] + 1;
  } else if (X <= 2 + 2*a[N-1]) {
    // cout << "hoge2\n" <<  2 + a[N-1] << "\n" << 2 + 2*a[N-1] << endl;
    return p[N-1] + 1 + f(N-1, X-1-a[N-1]-1);
  } else{
    return 2 * p[N-1] + 1;
  }
}

int main() {
  int N;
  long X;
  cin >> N >> X;
  // cout << X << endl;
  a[0] = 1;
  p[0] = 1;
  for (int i = 1;i < N + 1; i++) {
    // cout << i << endl;
    a[i] = 2 * a[i-1] + 3;
    p[i] = 2 * p[i-1] + 1;
    // cout << a[i] << "\n" << p[i] << endl;
  }
  // cout << a[49] << p[49];
  // cout << a[50] << p[50];
  cout << f(N, X);
}
