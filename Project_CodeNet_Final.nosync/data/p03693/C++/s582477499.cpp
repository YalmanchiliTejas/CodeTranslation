#include<bits/stdc++.h>
using namespace std;

int k, r, b, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> b >> q;
    k = r * 100 + b * 10 + q;
    if (k % 4 == 0) cout << "YES";
    else cout << "NO";
}

