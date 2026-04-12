#include<bits/stdc++.h>
using namespace std;
int main()
{
    int res = 0,sum = 0;
    int n; cin>>n;
    while(n--)
    {
        int x;
        cin >> x;
        res = (res + (1LL * x * sum) % 1000000007) % 1000000007;
        sum = (sum + x) % 1000000007;
    }
    cout << res;
    return 0;
}