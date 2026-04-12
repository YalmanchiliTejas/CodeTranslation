#include<iostream>
using namespace std;

int main(){
   int a[3];
   cin >> a[0] >> a[1] >> a[2];
   int p = a[1]*10 + a[2];
   if (p%4==0){
     cout << "YES" << endl;
   }
   else {
      cout << "NO" << endl;
   }
}