#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll n, x, ans, y;
int main(void){
    // Your code here!
    cin >> n >> x;
    y = x;
    n++;
    while(n > 1 && x > 0){
        if (x == 1){
            x = 0, ans++;
        } else if (x == pow(2, n) - 1){
            x = 0, ans += pow(2, n - 1) - 1;
        } else if (x == pow(2, n + 1) - 3){
            x = 0, ans += pow(2, n) - 2;
        } else if (x > 1 && x < pow(2, n) - 1){
            x--, ans++;
        } else {
            x -= pow(2, n) - 1, ans += pow(2, n - 1) - 1;
        }
        n--;
    }
    cout << y - ans << endl;
}
