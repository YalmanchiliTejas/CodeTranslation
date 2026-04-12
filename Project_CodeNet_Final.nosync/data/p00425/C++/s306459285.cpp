#include <iostream>
#include <string>
#include <utility>
using namespace std;

#define DUMP(x)  cerr << #x << " = " << (x) << endl;


void rotate(int *a, int *b, int *c, int *d) {
  int temp;

  temp = *d;
  *d = *c;
  *c = *b;
  *b = *a;
  *a = temp;
}

int main(int argc, char const* argv[])
{
  int i, n, total;
  string input;

  int up = 1, bottom = 6, left = 4, right = 3, front = 2, back = 5;

  while (true) {
    cin >> n;
    if (n == 0) { break; }

    up = 1;
    bottom = 6;
    left = 4;
    right = 3;
    front = 2;
    back = 5;
    total = 1;

    for (i = 0; i < n; i++) {
      cin >> input;

      if (input == "North") {
        rotate(&up, &back, &bottom, &front);
      } else if (input == "East") {
        rotate(&up, &right, &bottom, &left);
      } else if (input == "West") {
        rotate(&up, &left, &bottom, &right);
      } else if (input == "South") {
        rotate(&up, &front, &bottom, &back);
      } else if (input == "Right") {
        rotate(&front, &left, &back, &right);
      } else if (input == "Left") {
        rotate(&front, &right, &back, &left);
      }

      total += up;
    }

    cout << total << endl;
  }
  return 0;
}