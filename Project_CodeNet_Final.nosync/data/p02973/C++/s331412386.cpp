#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];

    vector<int> res;
    res.push_back(a[0]);
    rep(i, 1, n)
    {
        vector<int>::iterator itr = lower_bound(res.begin(), res.end(), a[i]);
        if (itr == res.begin())
            res.insert(itr, a[i]);
        else
            res[itr - res.begin() - 1] = a[i];
    }
    cout << res.size() << endl;
    return 0;
}