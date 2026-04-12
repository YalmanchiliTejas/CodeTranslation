#include <iostream>

using namespace std;

int main()
{
    int n, height, max = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> height;
        if (max <= height)
        {
            max = height;
            ans++;
        }
    }
    cout << ans;
}