#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>
using namespace std;
//整形Shift + alt + f　2回
//int x[101],y[101],h[101];
//int koya[100001][];
/*
//ユークリッドの互除法
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
*/
int n;
int main()
{
    cin >> n;

    if (n == 7 || n == 5 || n == 3)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}