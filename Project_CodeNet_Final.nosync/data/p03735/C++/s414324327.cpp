#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

const int maxN = 2e5 + 10;

struct TBag{
    int x,y;

    bool operator < (const TBag& t) const{
        return x < t.x;
    }
};

int             n;
int             x[maxN], y[maxN];
multiset<int>   r,b;
TBag            a[maxN];

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x,y;
        cin >> x >> y;
        if(x > y)
            swap(x, y);
        a[i] = {x,y};
        r.insert(x);
        b.insert(y);
    }

    sort(a + 1, a + n + 1);

    int res = (*r.rbegin() - *r.begin()) * (*b.rbegin() - *b.begin());

    for(int i = 1; i <= n; ++i){
        int x = a[i].x;
        int y = a[i].y;
        r.erase(r.find(x));
        b.insert(x);
		b.erase(b.find(y));
		r.insert(y);
        res = min(res, (*r.rbegin() - *r.begin()) * (*b.rbegin() - *b.begin()));
    }

    cout << res;
    return 0;
}
