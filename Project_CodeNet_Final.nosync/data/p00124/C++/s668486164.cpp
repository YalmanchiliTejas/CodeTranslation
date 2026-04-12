#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
    bool f = false;
    while (true) {
        int n; cin >> n; if (n == 0) break;
        if (f) cout << endl;
        else f = true;
        vector<pair<pair<int, int>, string> > v;
        for (int i = 0; i < n; ++i) {
            string t;
            int a, b, c;
            cin >> t >> a >> b >> c;
            v.pb(mp(mp(3*a+c, -i), t));
        }
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < n; ++i)
            cout << v[i].second << "," << v[i].first.first << endl;
    }
    return 0;
}