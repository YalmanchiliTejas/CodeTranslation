#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(void){
    ll a,b,c,x,y,price=0; cin >> a >> b >> c >> x >> y;
    if(2*c < a+b){
        int min_xy = min(x,y);
        price += min_xy*c*2;
        x -= min_xy, y -= min_xy;
    }
    if(2*c < a) price += 2*c*x;
    else price += a * x;
    if(2*c < b) price += 2*c*y;
    else price += b * y;    

    cout << price << endl;

    return 0;
}