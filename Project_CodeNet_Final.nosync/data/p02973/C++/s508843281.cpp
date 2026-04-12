#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    multiset<int> st;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    st.insert(-a[0]);
    for (int i = 1;i < n;++i) {
        auto it = st.upper_bound(-a[i]);
        if (it == st.end()) st.insert(-a[i]);
        else {
            st.erase(it);
            st.insert(-a[i]);
        }
    }
    cout << st.size() << endl;
    return 0;
}