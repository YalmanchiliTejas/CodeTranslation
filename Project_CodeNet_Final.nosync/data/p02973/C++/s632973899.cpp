#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

int main()
{
    int N;
    cin >> N;
    multiset <int> st;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        auto k = st.lower_bound(x);
        if (k != st.begin()) st.erase(--k);
        st.insert(x);
    }
    cout << st.size() << endl;
    return 0;
}
