#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;

    int min_v = min(a+b, ab*2);

    int ans = 0;
    if(min_v == a+b){
        //cout << a*x + b*y << endl;
        ans = min(x, y) * a + min(x, y) * b;
        if(min(x, y) == x){
            if(b >= ab*2){
                ans += ab*2 * (y-x);
            }
            else {
                ans += b * (y-x);
            }
        }
        else {
            if(a >= ab*2){
                ans += ab*2 * (x-y);
            }
            else {
                ans += a * (x-y);
            }
        }
        cout << ans << endl;
    }
    else {
        ans = min(x, y) * ab*2;
        if(min(x, y) == x){
            if(b >= ab*2){
                ans += ab*2 * (y-x);
            }
            else {
                ans += b * (y-x);
            }
        }
        else {
            if(a >= ab*2){
                ans += ab*2 * (x-y);
            }
            else {
                ans += a * (x-y);
            }
        }
        cout << ans << endl;
    }

}