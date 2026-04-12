#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, mod = 1000000007;
    cin >> N;
    int arr[N];
    long long sum = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sum %= mod;
    }
    for (int i=0; i<N; i++)
    {
        sum -= arr[i];
         if (sum < 0) sum += mod;
        ans += arr[i] * sum;
        ans %= mod;
    }
    cout << ans <<" \n";
    return 0;
}
