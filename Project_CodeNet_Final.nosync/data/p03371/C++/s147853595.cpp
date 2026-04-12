#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <map>
#include <set>
#include <ios>
#include <iomanip>

using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int c_a = c - a;
    int c_b = c - b;
    while(x > 0 && y > 0 && c_a + c_b < 0){
        ans += 2 * c;
        x--;
        y--;
    }
    if(x != 0){
        if(a <= 2*c){
            ans += a * x;
        }else{
            ans += 2*c * x;
        }
    }
    if(y != 0){
        if(b <= 2*c){
            ans += b * y;
        }else{
            ans += 2*c * y;
        }
    }
    cout << ans;
}

