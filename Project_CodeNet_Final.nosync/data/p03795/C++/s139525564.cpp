#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    ll x = n * 800;
    ll y = (n / 15) * 200;
    
    cout << x - y << endl;
    return 0;
}