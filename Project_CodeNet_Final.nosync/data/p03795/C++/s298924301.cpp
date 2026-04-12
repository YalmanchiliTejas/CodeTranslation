
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    int y;
    y = (n / 15) * 200;
    cout << 800 * n - y << endl;
}