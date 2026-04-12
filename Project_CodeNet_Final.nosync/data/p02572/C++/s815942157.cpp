#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long Mod = 1000000007;
    long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long sum1=0;
    long sum2=0;
    for (int i = 0; i < n; i++)
    {
        sum1 = (sum1 + a[i]) % Mod;
        sum2 = (sum2 + (a[i] * a[i]) % Mod ) % Mod;
    }
    cout << ( ( (sum1 * sum1) % Mod + Mod - sum2) % Mod * 500000004) % Mod << endl;
    
}