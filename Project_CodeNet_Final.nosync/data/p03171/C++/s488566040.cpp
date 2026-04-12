#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> a;
vector<vector<ll> > dp;
vector<vector<bool> > flag;

//区間[l,r)
ll func(int l, int r) {
    if (l > r)
        return 0;

    if (flag[l][r])
        return dp[l][r];
    
    flag[l][r] = true;
    return dp[l][r] = max(a[l] - func(l+1, r), a[r] - func(l, r-1));
}

int main() {
    int n;  cin >> n;
    a.resize(n);
    dp.resize(n, vector<ll>(n, 0));
    flag.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << func(0, n-1) << endl;

    return 0;
}