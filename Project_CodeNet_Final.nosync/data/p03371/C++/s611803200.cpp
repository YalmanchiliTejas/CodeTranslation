#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
    ll a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    if(a+b <= 2*c){
        cout << a*x + b*y << endl;
    }else{
        if(x >= y){
            if(2*c > a) cout << (x-y)*a + 2*y*c << endl;
            else cout << 2*x*c << endl;
        }else{
            if(2*c > b) cout << (y-x)*b + 2*x*c << endl;
            else cout << 2*y*c << endl;
        }
    }
}