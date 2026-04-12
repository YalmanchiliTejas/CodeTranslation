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
#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<=n;i++)
using namespace std;
typedef unsigned long ul;
typedef pair<ul, ul> P;


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
 int N;
 cin >> N;
 vector<int> H(N);
 REP(i,N){
     cin >> H[i];
     
 }
int ans = 0;
REP(i,N){
    bool high = true;
   for(int j = i-1; j>=0; j--){
        if(H[i]<H[j]) high = false;
    }
    if(high == true){
        ans++;
    }
}
cout << ans << endl;

}