#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n, h[20],ans=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        int m=0;
        for (int j = 0; j < i; j++) {
            if ( h[i] < h[j]) m++;
        }
        if (m == 0) ans++;
    }
    cout << ans << endl;

}
     

