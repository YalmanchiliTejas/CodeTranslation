#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

int main() {
    long long int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=2*c){
        cout << x*a+y*b;
    }else{
        if(x>=y){
            if(2*c<=a){
                cout << 2*c*y+2*c*(x-y);
            }else{
                cout << 2*c*y+a*(x-y);
            }
        }else{
            if(2*c<=b){
                cout << 2*c*x+2*c*(y-x);
            }else{
                cout << 2*c*x+b*(y-x);
            }
        }
    }
}