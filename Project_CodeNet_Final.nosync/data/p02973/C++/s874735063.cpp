#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cout << (#x) << " = " << (x) << "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

void Main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    deque<int> d;
    rep(i,n){
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(p == 0){
            d.push_front(a[i]);
        }
        else d[p-1] = a[i];
    }
    int ans = d.size();
    cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
