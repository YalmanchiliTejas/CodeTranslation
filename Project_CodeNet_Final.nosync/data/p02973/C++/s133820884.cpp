#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;

int n , a[100001] , ans;
multiset <int> ms;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        auto u = ms.lower_bound(a[i]);
        if (u == ms.begin()){
            ms.insert(a[i]);
            ans++;
        }else{
            --u;
            ms.erase(u);
            ms.insert(a[i]);
        }
    }
    cout << ans;
}
