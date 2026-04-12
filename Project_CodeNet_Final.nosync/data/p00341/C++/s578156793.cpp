#include <iostream>
using namespace std;

bool isRectangle(int a[]) {
  if (!(a[0] == a[1] && a[2] == a[3])) return false;
  if (!(a[4] == a[5] && a[6] == a[7])) return false;
  if (!(a[8] == a[9] && a[10] == a[11])) return false;
  return true;
}

int main() {
  int e[12];
  for (int i = 0; i < 12; i++)
    cin >> e[i];

  for (int i = 0; i < 12; i++)
    for (int j = i; j > 0; j--)
      if (e[j - 1] > e[j]) {
	int t = e[j - 1];
	e[j - 1] = e[j];
	e[j] = t;
      }

  if (isRectangle(e)) cout << "yes" << endl;
  else cout << "no" << endl;

  return 0;
}