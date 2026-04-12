#include <iostream>
using namespace std;
int main(void){
    // Your code here!
   int r, g, b;
   cin >> r >> g >> b;
   
   int ans = r*100 + g*10 + b;
   
   if(ans%4 == 0)
    cout << "YES" << endl;
    
else
cout << "NO" << endl;
    
}
