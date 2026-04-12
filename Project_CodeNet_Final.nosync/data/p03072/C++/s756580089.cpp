#include <iostream>
using namespace std;
int main(void){
    int n, h[30];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    
    int x = h[0], ans = 1;
    for (int i = 1; i < n; i++) {
        if (x <= h[i]) {
            ans++;  x = h[i];
        }
    }
    
    cout << ans << endl;
}
