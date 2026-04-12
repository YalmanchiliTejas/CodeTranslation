#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;

    if(a + b <= 2 * c){
        ans += (a + b) * min(x, y);
    }
    else{
        ans += (2 * c) * min(x, y);
    }

    if(x < y){
        if(b <= 2 * c){
            ans += b * (y - x);
        }
        else{
            ans += (2 * c) * (y - x);
        }
    }
    else{
        if(a <= 2 * c){
            ans += a * (x - y);
        }
        else{
            ans += (2 * c) * (x - y);
        }
    }
    cout << ans << endl;
    return 0;
}