#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    long long x, y;
    cin >> x >> y;

    int sum = 0;
    int ans = 0;
    if(a + b <= c * 2){
        sum = a + b;
        if(x < y){
            ans += sum * x;
            ans += b * (y - x);
        }else if(x == y){
            ans += sum * x;
        }else{
            ans += sum * y;
            ans += a * (x - y);
        }
    }else{
        sum = c * 2;
        if(x < y){
            ans += sum * x;
            if(b <= sum){
                ans += b * (y - x);
            }else{
                ans += sum * (y - x);
            }
        }else if(x == y){
            ans += sum * x;
        }else{
            ans += sum * y;
            if(a <= sum){
                ans += a * (x - y);
            }else{
                ans += sum * (x - y);
            }
        }
    }

    cout << ans << endl;
}