#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::vector;
using std::string;

int main(){
    long a,b,c,x,y;
    long res,tmp;
    cin >> a >> b >> c >> x >> y;
    res = a*x + b*y;
    res = std::min(res,std::max(x,y)*c*2);
    if(x < y){
        res = std::min(res,c*x*2+b*(y-x));
    }else{
        res = std::min(res,c*y*2+a*(x-y));
    }
    cout << res;
}