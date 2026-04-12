#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int X, Y, Z;

int main() {
   cin >> X >> Y >> Z;
   cout << (X - Z) / (Z + Y) << endl;
   return 0;
}
