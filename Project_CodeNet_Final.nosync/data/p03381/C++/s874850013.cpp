#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n),b(n);

    for(int i = 0;i < n;i++){ cin >> a[i]; b[i] = a[i]; }

    sort(a.begin(),a.end());

    int me = a[n/2-1];

    for(int i = 0;i < n;i++)
    {
        if(b[i]<=me) cout << a[n/2] << endl;
        else cout << me << endl;
    }
}
