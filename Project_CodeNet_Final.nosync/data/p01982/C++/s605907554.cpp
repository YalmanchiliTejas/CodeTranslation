#include <iostream>
using namespace std;

int main(void){
    int n, l, r;
    while (cin >> n >> l >> r) {
        if (n == 0) return 0;
        
        int a[55];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int idx = n + 1;
            for (int j = 0; j < n; j++) {
                if (i % a[j] == 0) idx = min(idx, j + 1);
            }
            if (idx % 2) ans++;
        }
        cout << ans << endl;
        
    }
}

