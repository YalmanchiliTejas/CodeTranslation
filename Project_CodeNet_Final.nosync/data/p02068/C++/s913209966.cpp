#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max = 0;
    vector<int> v(n, 0);
    int x;

    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x > max) max = x;
        v[i] = x;
    }

    long long int ans = 0;

    for(int i = 2; i <= (int)sqrt(max); i++) {
        long long int tmp = 0;
        for(int j = 0; j < n; j++) {
            if(v[j] > 1 && v[j] % i == 0) {
                tmp += v[j];
            }
        }
        if(tmp > ans) ans = tmp;
    }

    for(int i = 0; i < n; i++) {
        long long int tmp = 0;
        if(v[i] == 1) continue;
        for(int j = 0; j < n; j++) {
            if(v[j] > 1 && v[j] % v[i] == 0) {
                tmp += v[j];
            }
        }
        if(tmp > ans) ans = tmp;
    }

    cout << ans << endl;

    return 0;
}

