#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;


int sumdigit(int x){
   int sum = 0;
    while(x != 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main(){
   int X,Y,Z;
   cin >> X >> Y >> Z;
    int x = X - Z*2;
    int m =0;
   for(int i = 1; i <= x / Y; i++){
       if(x >= i*Y + (i-1)*Z){
           m = max(m,i);
       }
   }
   cout << m << endl;
}