
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>

typedef long long ll;
const ll LL_MAX (1LL<<60);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll cnt(0);
    for(ll i=0; i<(1<<n); i++)
    {
        cout << cnt << ":";

        rep(j,0,n)
            if ((i & (1<<j)) > 0)
                cout << " " << j;

        cnt++;

        cout << endl;
    }

    return 0;
}

