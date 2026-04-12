#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> s(n);
    rep(i, 0, n) cin >> s[i];

    ll ans = 0;
    rep(c, 1, n)
    {
        ll score = 0;
        set<int> idx_set;
        int l = 0, r = n - 1;
        rep(x, 0, n)
        {  
            ll a = n - 1 - x * c;
            ll b = a - c;
            if (b <= 0) break;
            if (x*c>= n) break;
            
            if (idx_set.count(n-1-x*c) > 0)
                break;
            idx_set.insert(n-1-x*c);

            if (idx_set.count(x*c) > 0)
                break;
            idx_set.insert(x*c);


            score += s[x*c];
            score += s[n-1-x*c];
            
            ans = max(ans, score);
            // cout << c << ' ' << x << ' ' << score << endl;
        }
    }
    cout << ans << endl;
    return 0;
}