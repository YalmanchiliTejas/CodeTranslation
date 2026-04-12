#include <bits/stdc++.h>

#define pb push_back
#define mk make_pair
#define sc second
#define fr first

using namespace std;

typedef long long ll;

const long long N = (long long) 1e6 + 5;
const long long mod = (long long) 1e9 + 7;

pair<long long,long long> a[N];

long long n;
long long mn,mn1 = mod,mx,mx1,mnn,res,mxx;

int main () {
        ios_base::sync_with_stdio(false);

        cin >> n;

        for (long long i = 1; i <= n; i ++) {
                cin >> a[i].fr >> a[i].sc;
                if(a[i].fr > a[i].sc)
                        swap (a[i].fr,a[i].sc);
                mn1 = min (mn1,a[i].sc);
                mx1 = max (mx1,a[i].sc);
        }

        sort (a + 1,a + n + 1);

        mn = a[1].fr; mx = a[n].fr;

        res = (mx - mn) * 1ll * (mx1 - mn1);

        for (long long i = 1; i < n; i ++) {
                if(i > 1) mnn = min (mnn,a[i].sc);
                else mnn = a[i].sc;
                mxx = max (mxx,a[i].sc);

                res = min (res,(mx1 - mn) * 1ll * (max(mxx,a[n].fr) - min(a[i + 1].fr,mnn)));
        }
        cout << res << endl;
        return 0;
}
