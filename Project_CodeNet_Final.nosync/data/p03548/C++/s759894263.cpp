#include<iostream>
using namespace std;

int x,y,z,p = 0;

int main(){
    cin >> x >> y >> z;
    if(x < y + 2 * z){
        cout << p << endl;
        return 0;
     }
     p = 1;
     x = x - (y + z); 
     while(x >= y + 2 * z){
         p++;
         x = x - (y + z);
     }
     cout << p << endl;
}