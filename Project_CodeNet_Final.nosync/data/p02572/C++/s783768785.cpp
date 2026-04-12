#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int sum = 0;
    long long int res = 0;
    int mod = 1000000007;
    int n;

    cin >> n;
    vector<int> num(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
        sum %= mod;
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= num[i];
        if (sum < 0)
            sum += mod;
        ans += sum * num[i];
        ans %= mod;
    }
    cout << ans;
    return 0;
}