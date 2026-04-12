#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        
        ans += count(str.begin(), str.end(), '#');
    }
    
    if (ans == n + m - 1)
        cout << "Possible";
    else
        cout << "Impossible";

    return 0;
}
