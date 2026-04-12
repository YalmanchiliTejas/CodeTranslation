#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int ab = c * 2;

    long int aa = 0,bb = 0,ans = 0;

    int mm = min(x,y);

    bool ff = false;

    if(mm == x) ff = true;

    if(ab < a + b){
        ans += mm * ab;
    }else{
        ans += mm * (a + b);
    }

    if(ff){
        if(ab < b) ans += ab * (y - mm);
        else ans += b * (y - mm);
    }
    else{
        if(ab < a) ans += ab * (x - mm);
        else ans += a * (x - mm);
    }

    cout << ans << endl;
}