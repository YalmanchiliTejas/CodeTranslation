#include <iostream>
using namespace std;

int main(){
    long long ans = 0;
    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long b[n+1] = {};
    for (int i = n-1; i >= 0; i--)
    {
        b[i] = b[i+1] + a[i];
        b[i] = b[i] % 1000000007;
    }

    for (int i = 0; i < n; i++)
    {
        ans += b[i+1] * a[i];
        ans = ans % 1000000007;
    }
    cout << ans << endl;
}