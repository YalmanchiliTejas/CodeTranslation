#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

 int main(){
   int x, y, z;
   cin >> x >> y >> z;

   int num = x / (y + z);

   while(num >= 0){
     if(x >= y * num + z * (num + 1)){
       cout << num << endl;
       break;
     }
     num--;
   }
 }