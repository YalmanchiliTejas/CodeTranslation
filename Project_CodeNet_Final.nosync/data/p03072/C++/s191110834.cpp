#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int m = h[0];
    int ans = 1;
    for(int i = 1; i < n; i++)
    {
        if(h[i] >= m)
        {
            ans++;
            m = h[i];
        }
    }
    cout << ans << endl;
}
