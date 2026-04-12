#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, res=0, ok=1;
    cin >> N;
    int H[N];
    for (int i=0; i<N; i++) cin >> H[i];

    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (H[j] > H[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) res += 1;
        ok = 1;
    }
    
    cout << res << endl;
}