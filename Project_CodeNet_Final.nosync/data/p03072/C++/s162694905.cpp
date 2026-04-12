#include<iostream>
using namespace std;
int main() {
    int N,T,H,cnt=1;
    cin >> N;
    for (int i=0; i<N; i++) {
        if (i == 0) {
            cin >> T;
        } else {
            cin >> H;
            if (H == T) cnt++;
            if (H > T) {
                cnt++;
                T = H;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
