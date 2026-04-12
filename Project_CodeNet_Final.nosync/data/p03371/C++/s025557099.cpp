#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
//#define int long long

signed main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    int common = min(x, y);
    x -= common; y -= common;
    
    int price = common * ((a + b < c + c) ? a + b : c + c);
    
    if(x > y){
        price += min(x * a, x * c * 2);
    }else if(y > x){
        price += min(y * b, y * c * 2);
    }
    
    cout << price << endl;
}