#include <iostream>

using namespace std;

int n;
int arr[22];

int maxim;
int ans = 1;

int main()
{
    cin >> n;
    cin >> arr[1];
    maxim = arr[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= maxim)
            maxim = arr[i], ans++;
    }
    cout << ans;
    return 0;
}
