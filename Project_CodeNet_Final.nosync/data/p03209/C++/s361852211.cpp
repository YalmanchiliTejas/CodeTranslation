#include <iostream>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;

long long a(int n) {
    return pow(2, n + 2) - 3;
}
long long p(int n) {
    return pow(2, n + 1) - 1;
}

int main(void){
    long long n, x;
    cin >> n >> x;
    
    long long k, ans = 0;
    while (x > 0) {
        k = 0;
        while (a(k + 1) + n - k - 1 <= x) k++;
        if (k == 0) {
            if (x > n) ans += x - n;
            break;
        }
        
        ans += p(k);
        x -= a(k) + n - k;
        
        if (x > 0) {
            ans++;
            x--;
        }
        
        n = k;
    }
    
    cout << ans << endl;
}
