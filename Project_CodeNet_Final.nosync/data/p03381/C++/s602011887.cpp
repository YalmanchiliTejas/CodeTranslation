#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back
#define OK puts("OK");
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 1e6 + 5;

int n, ar[N], cur[N];

main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ar[i], cur[i] = ar[i];

    sort(ar + 1, ar + n + 1);

    for (int i = 1; i <= n; i++)
    {
        if ( cur[i] <= ar[ n / 2 ] )
            cout << ar[n / 2 + 1] << endl;
        else
            cout << ar[n / 2] << endl;
    }
}
