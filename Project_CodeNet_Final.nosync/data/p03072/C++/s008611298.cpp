#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int maxH = 0;
    int ans = 0;
    for (int i=0; i < N; ++i) {
        int H;
        cin >> H;
        if (H >= maxH) {
            ++ans;
        }
        if (H > maxH) maxH = H; 
    }
    
    cout << ans << endl;
    
    return 0;
}
