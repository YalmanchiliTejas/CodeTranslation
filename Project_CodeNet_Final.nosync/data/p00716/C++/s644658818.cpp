#include <iostream>
using namespace std;

int shoki;
int year;

int fukuri(double p, int c) {
  int A = shoki;
  int B;
  for (int i=0; i<year; i++) {
    B = A * p;
    A = A + B - c;
  }
  return A;
}

int tanri(double p, int c) {
  int A = shoki;
  int sum = 0;
  for (int i=0; i<year; i++) {
    sum +=  A * p;
    // cerr << "sum: " << sum << endl;
    A -= c;
  }
  return A+sum;
}

int main() {
  int d;
  scanf("%d", &d);
  for (int t=0; t<d; t++) {
    int n;
    scanf("%d%d%d", &shoki, &year, &n);
    // // cerr << n << endl;
    int max = shoki;
    for (int i=0; i<n; i++) {
      int tanpuku;
      double p;
      int c;
      scanf("%d%lf%d", &tanpuku, &p, &c);
      int gold;
      if (tanpuku) {
	gold = fukuri(p, c);
	// cerr << "fukuri" << endl;
      } else {
	gold = tanri(p, c);
	// cerr << "tanri" << endl;
      }
      // cerr << "gold: " << gold << endl;
      if (gold > max) {
        max = gold;
      }
    }
    printf("%d\n", max);
  }
}