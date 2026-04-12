#include<cstdio>
#include<iostream>

using namespace std;


int main() {
  long long a, b, ab, cost;
  int x, y;


  cin >> a >> b >> ab >> x >> y;

  cost = 0;


  while (x > 0 || y > 0) {
    if (2 * ab < a + b && x > 0 && y > 0) {
      x -= 1;
      y -= 1;
      cost += 2 * ab;
    } else if (2 * ab < a && x > 0) {
      x -= 1;
      cost += 2 * ab;
    } else if (2 * ab < b && y > 0) {
      y -= 1;
      cost += 2 * ab;
    } else {
      if (x > 0) { 
        x -= 1;
        cost += a;
      }
      if (y > 0) { 
        y -= 1;
        cost += b;
      }
    }
  }

  cout << cost << endl;

}
  

