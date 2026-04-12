#include <iostream>
#include <string>
using namespace std;
 
int main() { 
    int n, min = 0, ans = 0;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for(int i = 0; i < n; ++i) {
        if(h[i] >= min) {
            min = h[i];
            ans++;
        }
    }
    cout << ans << '\n';
}