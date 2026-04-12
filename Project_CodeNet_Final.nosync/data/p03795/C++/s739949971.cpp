#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    int x, y;
    x = 800 * n;
    y = 200 * (n / 15);
    cout << x - y << endl;
    
    return 0;
}