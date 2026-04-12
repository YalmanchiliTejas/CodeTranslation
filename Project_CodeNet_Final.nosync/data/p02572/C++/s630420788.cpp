#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const long long int m = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    lli a,x;
    cin >> x;
    lli s = 0;
    lli sp = 0;
    s = (s%m + x%m)%m;

    for(int i = 2;i<=n;i++)
    {
        cin >> x;
        sp = (sp%m + ((s%m*x%m)%m)%m)%m;
        s = (s%m + x%m)%m;
    }
    cout << sp << endl;
}
