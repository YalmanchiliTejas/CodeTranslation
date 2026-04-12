#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int a, b;
  char* ch;

  cin >> a >> b;
  if (a < b)
    ch = "<";
  else if (a > b)
    ch = ">";
  else
    ch = "==";
  printf("a %s b\n", ch);
}