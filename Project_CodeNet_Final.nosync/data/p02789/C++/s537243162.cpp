#include <bits/stdc++.h>


using ll = long long int;

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    
    cin >> n >> m;
    
    string ans = "No";
    if (n == m)
        ans = "Yes";
    
    cout << ans;
    
    return 0;
}