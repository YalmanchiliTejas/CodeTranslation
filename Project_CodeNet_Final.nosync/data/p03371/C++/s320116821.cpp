using namespace std;
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <cassert>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
 
    int simple_sum = x * a + y * b;
    int c_sum = max(x, y) * c * 2;
 
    int ab_amount;
    int a_amount;
    int b_amount;
 
    if (x < y){
 
        //int xquot = x / 2;
        //int yquot = y / 2;
 
        //int amod = x % 2;
        //int bmod = y - 2 * xquot;
        int bmod = y - x;

 
        ab_amount = c * x * 2;
        a_amount = a * 0;
        b_amount = b * bmod;
 
    } else {
 
        int amod = x - y;
 
        ab_amount = c * y * 2;
        a_amount = a * amod;
        b_amount = b * 0;
 
    }
    int opt_sum = ab_amount + a_amount + b_amount;
 
    cout << min(min(simple_sum, c_sum), opt_sum) << endl;
}
