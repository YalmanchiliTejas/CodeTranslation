#include <bits/stdc++.h> 
using namespace std; 
//#define endl "\n";
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    ll s = 0, ans = 0;
    for (int i = 0; i < n; i++) 
    {
        ans += s * vec[i];
        ans %= m;
        s += vec[i];
        s %= m;
    }
 
    cout << ans;
    return 0;
}
