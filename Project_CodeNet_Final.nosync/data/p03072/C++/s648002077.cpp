//
// Created on 2019/12/05.
//

#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(),x.end()
#define DEBUG

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int ans = 1;
    int heightMax = h[0];
    rep(i,n-1)
    {
        if(h[i+1] >= heightMax)
        {
            ++ans;
            heightMax = h[i+1];
        }
    }

    cout << ans << endl;
    return 0;
}