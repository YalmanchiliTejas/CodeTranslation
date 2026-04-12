#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <numeric>
#include <bitset>
#include <map>
#include <limits.h>

using namespace std;

/// 各桁の和
int sumdigit(int x){
   int sum = 0;
    while(x != 0){
        sum += x % 10;
        x /= 10;    
    }
    return sum;
}
/// 最大公約数 
int gcd(int x, int y){
      if(x<y){
          int temp = x;
          x = y;
          y = temp;
      }
      int r = x % y;
       while(r!=0){
           x = y;
           y = r;
           r = x % y;
       }
      return y;
   }



int main(){
int X;
cin >> X;
if(X == 7 || X==5 || X==3){
    cout << "YES" << endl;
}
else{
    cout << "NO" << endl;
}
}