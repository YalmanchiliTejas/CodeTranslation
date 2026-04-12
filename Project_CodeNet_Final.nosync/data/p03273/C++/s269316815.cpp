#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int H,W;
    cin >> H >> W;

    vector<string> a(H);
    for(int i=0;i<H;i++) {
        cin >> a[i];
    }

    vector<int> h(H,0);
    vector<int> w(W,0);
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(a[i][j] == '#') {
                h[i] = 1;
                w[j] = 1;
            }
        }
    }

    for(int i=0;i<H;i++) {
        if(h[i] == 0) continue;
        for(int j=0;j<W;j++) {
            if(w[j] == 0) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
