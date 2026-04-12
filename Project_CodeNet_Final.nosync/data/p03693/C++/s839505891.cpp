#include <iostream>
using namespace std;
int r,g,b ;
int main(){
   cin >> r>> g >> b ;
   if((100*r + 10 * g + b) % 4 ==0 ) cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}