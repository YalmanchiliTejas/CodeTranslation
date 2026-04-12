#include <bits/stdc++.h>

using namespace std;

long long a[3010];
int n;
long long res[3010][3010];

long long resi(int l, int d)
{
    if(l > d) return 0;
    if(res[l][d] != 0) return res[l][d];
    if(n % 2 != (d-l) % 2)
        res[l][d] = max(resi(l + 1, d) + a[l], resi(l, d - 1) + a[d]);
    else
        res[l][d] = min(resi(l + 1, d) - a[l], resi(l, d - 1) - a[d]);
    return res[l][d];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    cout << resi(0, n - 1);
    

    
    return 0;
}