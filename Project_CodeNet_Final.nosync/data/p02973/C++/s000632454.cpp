#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int arr[N], v[N];

int main() {
  //  freopen("in.txt", "rt", stdin);
    int n, x;
    scanf("%d", &n);
    int ans = 1;
    multiset<int> st;
    scanf("%d", &x);
    st.insert(x);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        auto it = st.lower_bound(x);
        if (it == st.begin()) {
            ++ans;
            st.insert(x);
            continue;
        }
        --it;
        st.erase(it);
        st.insert(x);
    }
    printf("%d", ans);
}