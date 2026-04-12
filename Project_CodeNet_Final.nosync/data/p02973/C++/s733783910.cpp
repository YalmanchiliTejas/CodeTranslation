#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <utility>
#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    multiset<int> st;
    int out = 0;

    for(int i = n - 1; i >= 0; --i) {
        int x = v[i];
        auto it = st.upper_bound(x);
        if(it == st.end()) {
            ++out;
            st.insert(x);
            continue;
        }

        st.erase(it);
        st.insert(x);
    }

    cout << out << endl;

    return 0;
}
