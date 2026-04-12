#include        <bits/stdc++.h>
using   namespace       std;
typedef long long ll;

// int/long:            -2,147,483,648 - 2,147,483,647 (-2^31 <= int < 2^31)
// long/long long:      -9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 (-2^63 <= long < 2^63)

#define INF (1<<30)
//1,073,741,824
//= 536,870,912 *2

#define MOD 1000000007

#define Rep0(i, n)      for (auto i=0; i<n; i++)
#define Rep1(i, n)      for (auto i=1; i<=n; i++)
#define Sort(P) sort(P.begin(), P.end())
#define Rev(P)  reverse(P.begin(), P.end())

int     main() {
        int X;
        cin >>X;
        if (X>=30)
                cout <<"Yes" <<endl;
        else
                cout <<"No" <<endl;
        return 0;
}