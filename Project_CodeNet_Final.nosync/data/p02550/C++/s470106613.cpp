#include <iostream>
#include <vector>

using namespace std;

long long f(long long x, long long m) {
    return x % m;
}

int main() {
    long long n, x, m;
    cin >> n >> x >> m;

    vector<long long> results(1, x);
    long long a = x;
    long long preCount = 0;
    long long preSum = x;
    long long setCount = 0;
    long long setSum = 0;
    for (int i = 1; i < n; i++) {
        a = f(a * a, m);
        preSum += a;
        for (int j = results.size() - 1; j >= 0; j--) {
            if (results[j] == a) {
                setCount = i - j;
                preCount = i;
                for (int k = 0; k < setCount; k++) {
                    setSum += results[j + k];
                }
                break;
            }
        }
        if (setCount) {
            break;
        }
        results.push_back(a);
    }
    if (!setCount) {
        cout << preSum << endl;
        return 0;
    }

    long long setTime = (n - preCount - 1) / setCount;
    long long remain = (n - preCount - 1) % setCount;
    long long subSum = 0;
    for (int i = 0; i < remain; i++) {
        a = f(a * a, m);
        subSum += a;
    }

    cout << preSum + setTime * setSum + subSum << endl;
    return 0;
}