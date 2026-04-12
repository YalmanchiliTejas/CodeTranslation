#include <iostream>
using namespace std;

int main(){
 int r,g,b;
 cin >> r >> g >> b;
 b+=r*100+g*10;
 if(b%4==0){
     cout << "YES" << endl;
 }   
 else  cout << "NO" << endl;
 return 0;
}