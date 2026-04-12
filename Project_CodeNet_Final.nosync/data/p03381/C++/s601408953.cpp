#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".in", "r")){
        freopen(Task".in", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> res(n);
    for (int i=0; i<n; ++i){
        cin >> a[i].fi; a[i].se = i;
    }
    sort(a.begin(), a.end());
    for (int i=0; i<n; ++i){
        if (i < n / 2){
            res[a[i].se] = a[n / 2].fi;
        }
        else{
            res[a[i].se] = a[n / 2 - 1].fi;
        }
    }
    for (int i=0; i<n; ++i)
        cout << res[i] << '\n';
}
