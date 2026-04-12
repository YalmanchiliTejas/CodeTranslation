#include<iostream>
using namespace std;
int main() {
    while (1) {
        int n; cin >> n;
        if (n == 0) break;
        int sum = 0;
        int max, min;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            if (i == 0) max = min = a;
            max = max < a ? a : max;
            min = min > a ? a : min;
            sum += a;
        }
        sum -= max + min;
        cout << sum / (n - 2) << endl;
    }
    return 0;
}

