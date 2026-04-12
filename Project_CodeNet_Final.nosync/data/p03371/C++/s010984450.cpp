#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<utility>
#include<cctype>
#include<climits>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"

typedef long long ll;



int atcoder(){
    //入力
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    
    //処理
    if(x<y){
        swap(a,b);
        swap(x,y);
    }
    if(a+b<=2*c){
        ans = a*x + b*y;
    }else{
        ans += 2*c*y;
        if(a<=2*c) ans += a*(x-y);
        else ans += 2*c*(x-y);
    }
    
    //出力
    cout << ans << ENT;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
