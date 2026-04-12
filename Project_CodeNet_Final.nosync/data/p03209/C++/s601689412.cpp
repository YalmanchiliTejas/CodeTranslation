#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long int n, x;
    cin >> n >> x;

    long int ans = 0;
    for(long int i = n; i > 0; i--){
        if (pow(2, i + 2) - 3 > 2 * x - 1) {
            if (x == 1) {
                cout << ans << '\n'; 
                return 0;
            }else{
                x = x - 1;
            }
        }else if (pow(2, i + 2) - 3 == 2 * x - 1){
            ans += pow(2, i);
            cout << ans << '\n';
            return 0;
        }else{
            if (x == pow(2, i + 2) - 3) {
                ans += pow(2, i + 1) - 1;
                cout << ans << '\n';
                return 0;
            }else{
                ans += pow(2, i);
                x = x - pow(2, i + 1) + 3 - 2;
                // cout << "ans = " << ans << '\n';
                // cout << "x = " << x << '\n';
            }
        }
    }
    ans++;
    cout << ans << "\n";
}