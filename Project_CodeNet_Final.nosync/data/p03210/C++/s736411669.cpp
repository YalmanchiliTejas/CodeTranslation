#include <iostream>
using namespace std;
int main() {
   int X;
   cin >> X;
   switch (X) {
   case 3:
   case 5:
   case 7:
      cout << "YES";
      break;
   default:
      cout << "NO";
      break;
   }
   cout << endl;
   return 0;
}