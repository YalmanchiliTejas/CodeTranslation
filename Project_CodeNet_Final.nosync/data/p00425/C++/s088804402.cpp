#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void Dicewap(int *dice, int a, int b, int c, int d);

int main()
{
  int n;
  string in;

  while (scanf("%d", &n), n){
    int dice[] = {0, 1, 2, 3, 4, 5, 6};
    int sum = 1;
    for (int i = 0; i < n; i++){
      cin >> in;
      if (in == "North") Dicewap(dice, 1, 2, 6, 5);
      if (in == "East") Dicewap(dice, 1, 4, 6, 3);
      if (in == "West") Dicewap(dice, 1, 3, 6, 4);
      if (in == "South") Dicewap(dice, 1, 5, 6, 2);
      if (in == "Right") Dicewap(dice, 2, 3, 5, 4);
      if (in == "Left") Dicewap(dice, 2, 4, 5, 3);
      sum += dice[1];
    }
    printf("%d\n", sum);
  }

  return (0);
}

void Dicewap(int *dice, int a, int b, int c, int d)
{
  int tmp = dice[a];
  dice[a] = dice[b];
  dice[b] = dice[c];
  dice[c] = dice[d];
  dice[d] = tmp;
}