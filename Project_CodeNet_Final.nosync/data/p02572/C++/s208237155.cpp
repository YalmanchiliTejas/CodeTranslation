#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int mod = 1000000007;
    
    long long S = 0;
    for (int i = 0; i < n; i++)
    {
        S += A[i];
    }
    long long ans = 0;
    long long s = S;
    for (int i = 0; i < n-1; i++)
    {
        s -= A[i];
        long long s_mod = s%mod;
        ans += s_mod*A[i];
        ans %= mod;
    }
    cout << ans << endl;
}