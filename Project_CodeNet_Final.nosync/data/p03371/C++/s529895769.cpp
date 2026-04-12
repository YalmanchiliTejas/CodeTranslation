#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;



int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b <= 2 * c){
        cout << a * x + b * y << endl;
        return 0;
    }else if (x < y){
            cout << min(2 * c * x + b * (y - x), 2 * c * y) << endl;
            return 0;
    }else{
        cout << min(2 * c * y + a * (x - y), 2 * c * x) << endl;
        return 0;
    }
}