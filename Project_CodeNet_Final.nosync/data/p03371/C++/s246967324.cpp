#include <bits/stdc++.h>
using namespace std;
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20);} } fast;

int main() {
    int a, b, c, x, y, m, x1;
    cin >> a >> b >> c >> x >> y;
    if (x > y){
        m = x;
    }else{
        m = y;
    }
    if (m == x) {
        x1 = a;
    }else{
        x1 = b;
    }
    if ((a + b) / 2.0 > c){
        if (x1 > 2 * c){
            cout << 2 * m * c << endl; 
        }else if (m == x){
            cout << (x + y - m) * 2 * c + ((m - (x + y - m)) * a) << endl;
        }else{
            cout << (x + y - m) * 2 * c + ((m - (x + y - m)) * b) << endl;
        }
    }else{
        cout << x * a + y * b << endl;
    }
}