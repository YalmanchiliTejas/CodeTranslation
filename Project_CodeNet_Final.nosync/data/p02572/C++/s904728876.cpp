#include <iostream>

using namespace std;

int main() {
    int mod = 1000000007;
    int N;
    cin >> N;

    long long int* a = new long long int[N];
    long long int sum = 0;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }


    long long int ans = 0;

    for (int i = 0; i < N-1; i++) {
        sum -= a[i];
        if (sum < 0) {
            sum += mod;
        }
        ans += sum * a[i];
        ans %= mod;
    }

    cout << ans << endl;


    delete[] a;

    return 0;
}