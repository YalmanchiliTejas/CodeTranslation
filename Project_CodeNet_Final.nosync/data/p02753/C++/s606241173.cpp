
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

    string s;
    cin >> s;

    char prev(s[0]);
    for (auto i: s)
    {
        if (prev != i)
        {
            cout << "Yes" << endl;
            return 0;
        }
        prev = i;
    }

    cout << "No" << endl;

    return 0;
}
