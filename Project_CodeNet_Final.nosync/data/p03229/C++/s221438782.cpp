#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int n; cin >> n;
    vector<ll> v(n);
    REP(i,n) cin >> v[i];
    sort(ALL(v));
    vector<ll> v1, v2;
    ll ans1 = 0,ans2 = 0;
    if (n == 2) ans1 = v[1] - v[0];
    else {
        int r = v.size() -1, l = 0;
        ans1 = v[r] - v[l];
        v1.push_back(v[r]);
        r--;
        ans1 += v[r] - v[l];
        v1.push_back(v[r]);
        r--;
        l++;
        int cnt = 0;
        while(l <= r) {
            int t = cnt % 4;
            if (t < 2) {
                ans1 += abs(v1[v1.size() -2] - v[l]);
                v1.push_back(v[l]);
                l++;
            } else {
                ans1 += abs(v1[v1.size() -2] - v[r]);
                v1.push_back(v[r]);
                r--;
            }
            cnt++;
        }

        r = v.size() -1, l = 0;
        ans2 = v[r] - v[l];
        v2.push_back(v[l]);
        l++;
        ans2 += v[r] - v[l];
        v2.push_back(v[l]);
        l++;
        r--;
        cnt = 0;
        while(l <= r) {
            int t = cnt % 4;
            if (t < 2) {
                ans2 += abs(v2[v2.size() -2] - v[r]);
                v2.push_back(v[r]);
                r--;
            } else {
                ans2 += abs(v2[v2.size() -2] - v[l]);
                v2.push_back(v[l]);
                l++;
            }
            cnt++;
        }

    }
    cout << max(ans1,ans2) << '\n';

    return 0;
}