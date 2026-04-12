#include<iostream>

using namespace std;

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int sum = 0;
        int max = 0;
        int min = 100000;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            sum += a;
            if (max < a) max = a;
            if (min > a) min = a;
        }
        sum -= min + max;
        cout << sum / (n - 2) << endl;
    }
}