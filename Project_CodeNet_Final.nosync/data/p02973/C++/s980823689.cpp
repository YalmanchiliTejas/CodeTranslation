#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        auto it = st.lower_bound(a);
        if (it == st.begin()) {
            st.insert(a);
        } else {
            it--;
            st.erase(it);
            st.insert(a);
        }
    }

    cout << st.size() << endl;

    return 0;
}