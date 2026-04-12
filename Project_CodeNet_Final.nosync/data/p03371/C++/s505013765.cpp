#include<iostream>

using namespace std;

int main(){
    int a_en, b_en, ab_en, x, y;
    cin >> a_en >> b_en >> ab_en >> x >> y;

    unsigned long long ans = 0;
    if(a_en+b_en > ab_en*2){
        int tmp = min(x,y);
        ans += ab_en * tmp * 2;
        x -= tmp;
        y -= tmp;
    }
    if(a_en > ab_en*2){
        ans += ab_en * x * 2;
        x = 0;
    }
    if(b_en > ab_en*2){
        ans += ab_en * y * 2;
        y = 0;
    }
    ans += a_en * x;
    ans += b_en * y;

    cout << ans << endl;
}
