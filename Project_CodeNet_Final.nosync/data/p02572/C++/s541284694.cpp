#include <string>
#include <iostream>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);

long long mod = 1e9 + 7;
using namespace std;
int main() {
    fastIO;
    int N;
    cin >> N;
    int a[N];
    long long sum = 0;
    for (int i = 0; i<N; i++){
        cin >> a[i];
        sum +=a[i];
        sum %= mod;
    }
    long ans = 0;
    for (int i = 0; i < N; i++)
    {
        sum -= a[i];
        if (sum < 0) sum += mod;
        ans += a[i] * sum;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
