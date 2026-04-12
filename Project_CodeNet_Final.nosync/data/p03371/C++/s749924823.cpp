#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define ve vector

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=c*2){
        int ans = a*x + b*y;
        cout << ans << endl;
        return 0;
    }else{
        int ans = 0;
        if(x>y){
            swap(x,y);
            swap(a,b);
        }
        ans += c*2*x;
        ans += (y-x)*(min(b,2*c));
        cout << ans << endl;
        return 0;
    }
}