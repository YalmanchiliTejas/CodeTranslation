#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int k, d[5] = {}, e[5] = {0, 1};
    cin >> n >> k;
    for(auto c : n) {
        for(int i = k; i >= 0; i--) {
            d[i + 1] += d[i] * 9;
            if(c != '0')
                d[i + 1] += e[i + 1] + e[i] * (c - '1'), e[i + 1] = e[i];
        }
    }
    cout << d[k + 1] + e[k + 1] << endl;
    return 0;
}
