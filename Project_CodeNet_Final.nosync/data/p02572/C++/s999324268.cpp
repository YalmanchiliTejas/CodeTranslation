#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int sum = 0;
    long long int m = 1000000007;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] % m;
        sum = (sum % m + arr[i]) % m;
    }
    long long int ans = 0;
    for (long long int i = 0; i < n; i++)
    {
        long long int k = (arr[i] * (sum - arr[i] + m) % m) % m;
        ans = (ans % m + k % m) % m;
        sum = (sum - arr[i] + m) % m;
    }
    cout << ans % m << endl;
}