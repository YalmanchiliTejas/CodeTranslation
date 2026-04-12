#include <iostream>
using namespace std;
int main(void){
    // Your code here!
   int r,g,b;
   int num;
   
   cin >> r >> g >> b;
   
   num = (10*g)+b;

   
   if(num%4==0)
        cout << "YES";
    else
        cout << "NO";
   
   
}
