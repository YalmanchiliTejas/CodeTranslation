#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    int a,b,c;
    long x,y; 
    cin >> a>> b>> c>> x >>y;
    long long cost=0;
    if(a+b<=2*c){
        cost=a*x+b*y;
    }else if (a+b > 2*c){
        if(x>=y){
            cost += 2*c*y;
            if(a > 2*c){
                cost += 2*c*(x-y);
            }else{
                cost += a*(x-y);
            }
        }else{
            cost += 2*c*x;
            if(b > 2*c){
                cost += 2*c*(y-x);
            }else{
                cost += b*(y-x);
            }
        }
    }
    

    
    cout << cost << endl;
    
    
    return 0;
}