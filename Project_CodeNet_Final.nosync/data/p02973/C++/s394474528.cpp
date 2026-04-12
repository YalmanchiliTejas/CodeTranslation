#include <bits/stdc++.h>
using namespace std;

const int N = 200002;

int a[N], b[N];

int main() {
        ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
        multiset <int> st; int n; cin >> n;
        for(int i = 1; i <= n; i++) {
                int x; cin >> x;
                auto it = st.lower_bound(x);
                if(it == st.begin()) st.insert(x);
                else {
                        --it;
                        st.erase(it);
                        st.insert(x);
                }

        }
        cout << st.size() << endl;


}
