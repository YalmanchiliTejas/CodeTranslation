#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//cout << std::fixed << std::setprecision(15) << y << endl;

int main() {
    ll a,b,c,x,y = 0;
    cin >> a >> b >> c >> x >> y;

    ll MIN = 1001001001;
    for(ll i = 0;i <= max(x,y);i++){
        ll aCnt,bCnt,abCnt = 0;
        if(x >= y){
            aCnt = i;
            if(x >= i){
                abCnt = (x - i) * 2;
            }
            if(y >= abCnt / 2){
                bCnt = y - abCnt / 2;
            }
            //cout << aCnt << " " << bCnt << " " << abCnt << endl;
            MIN = min(MIN,aCnt * a + bCnt * b + abCnt * c);
        }else{
            bCnt = i;
            if(y >= i){
                abCnt = (y - i) * 2;
            }
            if(x >= abCnt / 2){
                aCnt = x - abCnt / 2;
            }
            //cout << aCnt << " " << bCnt << " " << abCnt << endl;
            MIN = min(MIN,aCnt * a + bCnt * b + abCnt * c);
        }
        
    }
    cout << MIN << endl;
    return 0;
}