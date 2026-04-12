#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int H[110];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    int cnt = 0;
    int max = 0;

    for (int i = 0; i < N; ++i) {
        if(H[i] >= max) {
            max = H[i];
            cnt++;
        }
    }
    cout << cnt << endl;
}
