#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int ans = 1;
    int h0;
    cin >> h0;
    for(int i=0; i<N-1; i++) {
        int h1;
        cin >> h1;
        if(h1 >= h0) {
            ans ++;
            h0 = h1;
        }
    }
    cout << ans << endl;
    return 0;
}