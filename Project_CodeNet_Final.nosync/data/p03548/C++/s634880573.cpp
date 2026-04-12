#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
   int x, y, z;
   cin >> x >> y >>z;
   int a = x - z;
   int cnt = a / (z + y);
   cout << cnt << endl;
   return 0;
}
