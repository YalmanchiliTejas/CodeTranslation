#include <bits/stdc++.h>
using namespace std;

int main() 
{
   int r, g, b;
   cin >> r >> g >> b;

   int RGB = 100 * r + 10 * g + b;
   cout << (RGB % 4 == 0 ? "YES" : "NO") << endl;
}
