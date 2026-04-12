#include <iostream>
#include <cmath>

using namespace std;

long long a(long long n){
  return 2 * pow(2, n) - 1;
}

long long b(long long n){
  return 4 * pow(2, n) - 3;
}

long long L(long long X, long long n) {

  //cout << n << " " << X << endl;

  if (X < 1) return 0;
  if (n == 0) return 1;
  long long nb = b(n);

  // B1 L1(n - 1) P L2(n - 1) B2

  // B2以上
  if (nb <= X) return a(n);

  // L2以上
  if (nb / 2 + 1 < X) return a(n - 1) + 1 + L(X - (nb / 2 + 1), n - 1);

  // P
  if (nb / 2 + 1 == X) return a(n - 1) + 1;

  // L1以上
  if (1 < X) return L(X - 1, n - 1);

  // B1
  if (1 == X) return 0;
}

int main(void) {
  long long n, X;
  cin >> n >> X;
  cout << L(X, n) << endl;

  return 0;
}