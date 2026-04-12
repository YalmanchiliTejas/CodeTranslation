#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int h[110];

int main(){
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        bool whi = true;
        for (int j = 0; j < i; j++){
            if (h[j] > h[i]) {
                whi = false;
                break;
            }
        }
        if (whi) ans++;
    }
    cout << ans << endl;
}