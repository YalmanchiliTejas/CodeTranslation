#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n]; for(int &i : arr) cin >> i;

    int _max = -1, ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] >= _max)
        {
            _max = arr[i];
            ++ans;
        }
    }

    cout << ans;
    return 0;
}
