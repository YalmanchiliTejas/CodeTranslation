#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9+7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int r,g,b;
    cin >> r >> g >> b;
    if((g*10+b)%4==0) cout << "YES";
    else cout << "NO";
}
