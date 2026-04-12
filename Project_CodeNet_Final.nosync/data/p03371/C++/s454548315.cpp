#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b < 2*c){
        cout << a * x + b * y;
    }else{
        int p = min(x,y);
        int q = max(x,y);
        x -= p;
        y -= p;
        cout << min(2*c*p+a*x+b*y,2*c*q) << endl;
    }
    return 0;
}