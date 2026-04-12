#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    long long  a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    long long cnt1 = 0;
    long long tx = x, ty = y;
    cnt1 += min(tx, ty) * 2 * c;
    long long tmp = min(tx, ty);
    tx -= tmp;
    ty -= tmp;
    if(tx > 0){
        cnt1 += tx * a;
    }else if(ty > 0){
        cnt1 += ty * b;
    }
    long long cnt2 = 0;
    tx = x, ty = y;
    cnt2 += max(tx, ty) * 2 * c;
    tmp = max(tx, ty);
    tx -= tmp;
    ty -= tmp;
    if(tx > 0){
        cnt2 += tx * a;
    }else if(ty > 0){
        cnt2 += ty * b;
    }

    long long cnt3 = 0;
    cnt3 = a * x + b * y;
    cout << min(cnt1, min(cnt2, cnt3)) << endl;

    return 0;
}