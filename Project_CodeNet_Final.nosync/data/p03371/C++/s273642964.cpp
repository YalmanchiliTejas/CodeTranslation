#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >>c >>x >>y;
    
    long long sum = 1000000000;
    
    
    for(int i = 0; i <= 100000; i++) {
     long long k = 0;
      k = 2 * c * i + a * max(0, x - i) + b * max(0, y - i);
      sum = min(sum,k);
    }
    cout << sum;
}