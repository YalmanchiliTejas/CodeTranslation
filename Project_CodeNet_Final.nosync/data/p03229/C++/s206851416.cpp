#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[200005];
deque < ll > dq;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++) slld(arr[i]);

        sort(arr + 1, arr + 1 + n);

        dq.clear();

        dq.push_back(arr[n]);

        ll lft = 1;
        ll rgt = n - 1;

        ll sz = 0;

        while(lft <= rgt)
        {
            ll x = dq[0], y = dq[sz];

            ll e = abs(arr[lft] - x);
            ll f = abs(arr[lft] - y);

            ll g = abs(arr[rgt] - x);
            ll h = abs(arr[rgt] - y);

            ll mx = max(e,max(g,max(f,h)));

            if(mx == e)
            {
                dq.push_front(arr[lft]);
                lft++;
            }
            else if(mx == f)
            {
                dq.push_back(arr[lft]);
                lft++;
            }
            else if(mx == g)
            {
                dq.push_front(arr[rgt]);
                rgt--;
            }
            else
            {
                dq.push_back(arr[rgt]);
                rgt--;
            }

            sz++;
        }

//        for(i = 0; i < n; i++)
//        {
//            cout << dq[i] << " ";
//        }
//
//        cout << endl;

        ll sum = 0;

        for(i = 1; i < n; i++)
        {
            sum += abs(dq[i] - dq[i - 1]);
        }

        cout << sum << endl;
    }


}



