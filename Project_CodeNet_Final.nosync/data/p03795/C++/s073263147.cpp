#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{   
    int n;
    cin >> n;
    int x = n * 800;
    int cnt = n/15;
    int y = cnt*200;
    cout << x - y << endl;
    return 0;
}