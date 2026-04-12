#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if(a + b < 2*c){
        cout << a*x + b*y << endl;
    }
    else{
        ll t1, t2;
        if(x > y){
            t1 = c * x * 2;
            t2 = c * y * 2 + a * (x - y);
        }
        else{
            t1 = c * y * 2;
            t2 = c * x * 2 + b * (y - x);
        }
        cout << min(t1, t2) << endl;
    }
    return 0;
}
