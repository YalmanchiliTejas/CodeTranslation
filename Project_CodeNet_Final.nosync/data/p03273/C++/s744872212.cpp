#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int w, h;
    string a[100];
    bool xd[100] = {false};
    bool yd[100] = {false};
    
    cin >> h >> w;
    
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < h; i++) {
        for (int ii = 0; ii < w; ii++) {
            if (a[i][ii] == '#') {
                xd[ii] = true;
                yd[i] = true;
            }
        }
    }
    
    for (int i = 0; i < h; i++) {
        if (yd[i]) {
            for (int ii = 0; ii < w; ii++) {
                if (xd[ii]) {
                    cout << a[i][ii];
                }
            }
            
            cout << endl;
        }
        
    }
    
    return 0;
}