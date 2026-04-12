#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int x, y, a, b, c;
    cin >> a >> b >> c >> x >> y;
    ll sum = 0;
    if(a+b >= c*2){
        sum += min(x,y)*(c*2);
        if(max(x,y) == x){
            sum += min(a, c*2)*(abs(x-y));
        }
        else{
            sum += min(b, c*2)*(abs(x-y));
        }
    }
    else{
        sum += min(x,y)*(a+b);
        if(max(x,y) == x){
            sum += a*(abs(x-y));
        }
        else{
            sum += b*(abs(x-y));
        }
    }
    cout << sum << endl;
}