#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <climits>
#include <functional>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    vector<bool> v(n);
    long count = 0;
    function<void(int)> iter = [&](int node){
        v[node] = true;
        bool deadend = true;
        for (int i = 0; i < m; i++) {
            if (a[i] == node && !v[b[i]]) {
                iter(b[i]);
                deadend = false;
            } else if (b[i] == node && !v[a[i]]) {
                iter(a[i]);
                deadend = false;
            }
        }
        if (deadend) {
            if (all_of(v.begin(),
                       v.end(),
                       [](bool b){return b;})) {
                count += 1;
            }
        }
        v[node] = false;
    };
    iter(0);

    cout << count << endl;

    return 0;
}