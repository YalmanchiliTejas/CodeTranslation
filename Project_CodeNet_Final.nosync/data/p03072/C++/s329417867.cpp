#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <tuple>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    int maxi = 0;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (h[i] >= maxi) {
            ans++;
        }       
        
        maxi = max(maxi, h[i]);
    }
    
    cout << ans << endl;
}