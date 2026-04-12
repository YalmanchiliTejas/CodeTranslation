#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[1000001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        int t = lower_bound(arr, arr + n, m) - arr;
        if (t >= n)
            cout << n << endl;
        else cout << t << endl;
    }
}
