#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    char r, g ,b;
    string s;
    cin >> r >> g >> b;
    s += r; s+= g; s += b;
    int ans = stoi(s);
    if(ans%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}