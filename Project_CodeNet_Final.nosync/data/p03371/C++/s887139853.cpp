#include <iostream>
#include <algorithm>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
//#include <cmath>
#include <cstdlib>

using namespace std;

int main(){

    int a,b,c,x,y;
    
    cin >> a >> b >> c >> x >> y;

    long long int kane = a*x + b*y;

    while(x != 0 && y!= 0){
        if(kane + c*2 - a - b < kane){
            kane = kane + c*2 - a - b;
            x--;
            y--;
        }else{
            cout << kane;
            return 0;
        }
    }
    if(x == 0){
    while(y!= 0){
        if(kane + c*2 - b < kane){
            kane = kane + c*2 - b;
            y--;
        }else{
            cout << kane;
            return 0;
        }
    }
    }

    if(y == 0){
    while(x != 0){
        if(kane + c*2 - a < kane){
            kane = kane + c*2 - a;
            x--;
        }else{
            cout << kane;
            return 0;
        }
    }
    }
    
    cout << kane;
    return 0;
}