#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 0;

    if(a+b > c*2){
        int n = min(x,y);
        ans += c*2*n;
        x -= n;
        y -= n;
        if(x){
            if(a > c*2){
                ans += c*2*x;
            } else {
                ans += a*x;
            }
        } else if (y){
            if(b > c*2){
                ans += c*2*y;
            } else {
                ans += b*y;
            }
        }
    } else {
        ans += a*x;
        ans += b*y;
    }

    cout << ans << endl;
    return 0;
}
