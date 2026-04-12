#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if(a+b>c*2){
        int buy = min(x,y);
        ans += 2 * buy * c;
        x-= buy;
        y-= buy;
    }
    if(a > c*2){
        ans += 2 * x * c;
    }else{
        ans += x * a;
    }
    if(b > c*2){
        ans += 2 * y * c;
    }else{
        ans += y * b;
    }
    cout << ans << endl;
}