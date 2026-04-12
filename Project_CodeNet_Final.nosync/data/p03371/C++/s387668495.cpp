#include<bits/stdc++.h>
using namespace std;

int main(){
    int64_t a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int64_t ans = a*x+b*y;
    /*
    if(a+b > 2*c){
        int buy_c = min(x,y) * 2;
        ans += buy_c * c;
        int add_a = x-buy_c/2;
        int add_b = y-buy_c/2;
        ans += min(add_a*a, ((add_a+1)/2)*c);
        ans += min(add_b*b, ((add_b+1)/2)*c);
    }
    else{
        ans += a*x + b*y;
    }
    */
    for (int i=0; i<=max(x,y);i++){
        int64_t price = 0;
        price += 2*c*i;
        if(x-i >0){
            price += (x-i) * a;
        }
        if(y-i > 0){
            price += (y-i) * b;
        }
        ans = min(ans,price);
    }
    cout << ans << endl;
}