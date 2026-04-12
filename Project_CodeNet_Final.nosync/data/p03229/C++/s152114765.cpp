#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int main(void){
    int n, a[100010], b[100010];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    
    long long ans = 0;
    
    if (n % 2 == 0) {
        b[0] = a[(n - 1) / 2];
        b[n - 1] = a[n / 2];
        
        for (int i = 1; i < n - 1; i++) {
            if (i % 2 != 0) b[i] = a[n - 1 - i / 2];
            else b[i] = a[i / 2 - 1];
        }
    }
    else {
        if (a[n / 2] - a[n / 2 - 1] < a[n / 2 + 1] - a[n / 2]) {
            b[0] = a[n / 2];
            b[n - 1] = a[n / 2 - 1];
            
            for (int i = 1; i < n - 1; i++) {
                if (i % 2 != 0) b[i] = a[n - 1 - i / 2];
                else b[i] = a[i / 2 - 1];
            }
        }
        else {
            b[0] = a[n / 2];
            b[n - 1] = a[n / 2 + 1];
            
            for (int i = 1; i < n - 1; i++) {
                if (i % 2 != 0) b[i] = a[i / 2];
                else b[i] = a[n - i / 2];
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        ans += abs(b[i + 1] - b[i]);
//        cout << b[i] << " ";
    }
//    cout << b[n - 1] << endl;
    
    cout << ans;
    
    return 0;
}
