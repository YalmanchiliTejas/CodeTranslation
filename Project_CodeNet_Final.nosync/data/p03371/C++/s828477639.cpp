#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if(a+b <= 2*c){
        if(x > y){
            cout << min(y*(a+b) + (x-y)*a,x*(a+b)) << endl;
        }else{
            cout << min(x*(a+b) + (y-x)*b,y*(a+b)) << endl;
        }
    }else{
        if(x > y){
            cout << min(y*(2*c) + (x-y)*a,x*(2*c)) << endl;
        }else{
            cout << min(x*(2*c) + (y-x)*b,y*(2*c)) << endl;
        }
    }
    return 0;
}