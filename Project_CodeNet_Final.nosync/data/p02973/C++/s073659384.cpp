#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, a;  cin >> n;
    multiset<long long> st;
    for (int i = 0; i < n; i++) {
        cin >> a;
        auto ite = st.upper_bound(-a);
        if (ite == st.end()) {
            st.insert(-a);
            continue;
        }

        st.erase(ite);
        st.insert(-a);
    }

    cout << st.size() << endl;
    return 0;
}