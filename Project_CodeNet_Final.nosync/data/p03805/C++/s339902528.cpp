#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
    vector<int>a(n);
    for (int i = 1; i < n; i++)a.at(i) = i;
    set<pair<int, int>>ab;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        ab.insert({ x,y });
    }
    ll ans = 0;
    do {
        //処理
        if (a.at(0) != 0)break;
        bool x = true;
        set<pair<int, int>>abc = ab;
        for (int i = 0; i < n - 1; i++) {
            int k = a.at(i);
            int l = a.at(i + 1);
            if (k > l)swap(k, l);
            if (!abc.count({ k,l })) {
                x = false;
                break;
            }
        }
        if (x)ans++;
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}