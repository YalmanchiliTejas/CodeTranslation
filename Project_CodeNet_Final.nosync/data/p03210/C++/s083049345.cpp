#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <functional>
#include <set>
#include <iterator>

using namespace std;
typedef long long ll;
int X;

int main() {
   cin >> X;
   switch(X) {
      case 3:
      case 5:
      case 7:
         cout << "YES" << endl; break;
      default:
         cout << "NO" << endl; break;
   }
}