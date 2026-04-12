#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int rot[][6] = {2, 6, 3, 4, 1, 5, 
		4, 2, 1, 6, 5, 3,
		3, 2, 6, 1, 5, 4,
		5, 1, 3, 4, 6, 2,
		1, 3, 5, 2, 4, 6,
		1, 4, 2, 5, 3, 6};
int dise[6];

void rotation(int r)
{
  int tmp[6];
  for (int i = 0; i < 6; i++) {
    tmp[i] = dise[rot[r][i] - 1];
  }
  for (int i = 0; i < 6; i++) {
    dise[i] = tmp[i];
  }
}

int main()
{
  map<string, int> m;
  m["North"] = 0, m["East"] = 1, m["West"] = 2, m["South"] = 3, m["Right"] = 4, m["Left"] = 5;
  int N;
  while (scanf("%d ", &N) == 1) {
    if (N == 0) {
      break;
    }
    for (int i = 0; i < 6; i++) {
      dise[i] = i + 1;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
      string r;
      cin >> r;
      cin.ignore();
      rotation(m[r]);
      sum += dise[0];
    }
    printf("%d\n", sum + 1);
  }
  return 0;
}