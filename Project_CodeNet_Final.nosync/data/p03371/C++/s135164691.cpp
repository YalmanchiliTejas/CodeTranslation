#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=2*c)cout << a*x+b*y << endl;
    else{
        if(x<=y)cout << x*2*c+min((y-x)*b,(y-x)*2*c) << endl;
        else cout << y*2*c+min((x-y)*a,(x-y)*2*c) << endl;
    }
}