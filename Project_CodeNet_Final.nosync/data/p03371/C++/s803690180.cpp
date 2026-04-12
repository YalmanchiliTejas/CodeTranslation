#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 
int main (){
    ll a, b ,c ;
    cin >> a >> b >> c ;
    ll x, y ;
    cin >> x >> y ;
    if(2*c >= a+b){
        cout << a*x + b*y << endl ;
    }
    else {
        ll num = INF ; 
        if(x > y){
            rep(i, x + 1){
                if(y - i < 0){
                    b = 0 ;
                }
                if(num > a*(x - i) + b*(y - i) + 2*c*i){
                    num = a*(x - i) + b*(y - i) + 2*c*i ;
                }
            }
        }
        else {
            rep(i, y + 1){
                if(x - i < 0){
                    a = 0 ;
                }
                if(num > a*(x - i) + b*(y - i)+ 2*c*i){
                    num = a*(x - i) + b*(y - i) + 2*c*i ;
                }
            }
        }
        cout << num << endl ;
    }
}
