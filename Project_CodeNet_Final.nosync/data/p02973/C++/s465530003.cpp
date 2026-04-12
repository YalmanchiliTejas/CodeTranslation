#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using ll=long long;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vpii=vector<pii>;
using vvpii=vector<vpii>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi xs(n);
    for(auto& xi: xs)
        cin >> xi;
    multiset<int> last;
    for (int i=0; i<n; ++i) {
        auto it = last.lower_bound(xs[i]);  // first >= xs[i]  --> prev(it) < xs[i]
        if (it != last.begin())
            last.erase(std::prev(it));
        last.insert(xs[i]);
    }
    cout << last.size() << endl;
}
