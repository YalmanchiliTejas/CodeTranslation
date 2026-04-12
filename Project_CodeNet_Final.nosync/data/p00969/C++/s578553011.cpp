// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = a[j] - a[i];
            
            auto ind = lower_bound(a.begin(), a.begin() + i, a[i] - d) - a.begin();
            
            if (ind == i || a[ind] != a[i] - d) {
                int cnt = 2;
                int k = j;
                
                while(true) {
                    ind = lower_bound(a.begin() + k, a.end(), a[k] + d) - a.begin();
                    
                    if (ind == n || a[ind] != a[k] + d) {
                        break;
                    }
                    
                    k = ind;
                    cnt++;
                }
                
                ans = max(ans, cnt);
            }
        }
    }
    
    cout << ans << endl;
}

