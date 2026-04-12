#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int main() {
    abdelrahman010
    multiset<int> st;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(st.empty())
            st.insert(x);
        else {
            auto it = st.lower_bound(x);
            if(it != st.begin())
                st.erase(--it);
            st.insert(x);
        }
    }
    cout << st.size();
    return 0;
}