#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 110;

int n;
int h[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];

    int now = -1, res = 0;
    for(int i = 1; i <= n; i++)
        if(now <= h[i])
        {
            now = h[i];
            res++;
        }

    cout << res << endl;

    return 0;
}
