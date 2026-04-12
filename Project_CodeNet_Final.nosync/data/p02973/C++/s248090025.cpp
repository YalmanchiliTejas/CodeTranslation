#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    multiset <int, greater<int>> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (st.size() == 0) {
            st.insert(a);
        } else {
            auto itr = st.upper_bound(a);
            if (itr == st.end()) {
                st.insert(a);
            } else {
                st.erase(itr);
                st.insert(a);
            }
        }
    }

    cout << st.size() << "\n";
    return 0;
}