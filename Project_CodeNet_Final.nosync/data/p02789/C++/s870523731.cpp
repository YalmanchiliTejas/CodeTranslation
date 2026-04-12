/// WA

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
     
#define x first
#define y second
#define pb push_back
#define sz(x) (int) x.size()

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;

using ll = long long;
using pii = pair<int, int>;                                   

const int MOD = 1e9 + 7;
const int INF32 = 1e9 + 1e2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n == m)
        cout << "Yes";
    else
        cout << "No";        
    return 0;
}
