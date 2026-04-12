#include <iostream>
#include <vector>
 
#define rep(i, N) for (LL i = 0; i < N; ++i)
typedef long long int LL;
 
using namespace std;
 
int main() {
    LL N, r = 0;
    vector<LL> H(100);
    cin >> N;
    rep(i, N) cin >> H[i];
    for (LL i = 0; i < N; ++i) {
        bool check = true;
        for (LL j = 0; j < i; ++j) {
            if (H[i] < H[j]) {
                check = false;
              	break;
            }
        }
        if (check) r++;
    }
 
    cout << r << endl;
    return 0;
}