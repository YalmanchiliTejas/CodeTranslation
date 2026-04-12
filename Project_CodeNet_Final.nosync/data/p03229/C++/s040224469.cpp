#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end());
    
    long long ans = 0;
    for (int _ = 0; _ < 2; _++) {
        int il = 1, ir = n-1;
        deque<long long> que;
        que.push_back(a[0]);
        while (il != ir) {
            vector<long long> d(4);
            d[0] = abs(que.front() - a[il]);
            d[1] = abs(que.back() - a[il]);
            d[2] = abs(que.front() - a[ir]);
            d[3] = abs(que.back() - a[ir]);
            long long mx = *max_element(d.begin(), d.end());
            if (mx == d[0]) que.push_front(a[il++]);
            else if (mx == d[1]) que.push_back(a[il++]);
            else if (mx == d[2]) que.push_front(a[ir--]);
            else que.push_back(a[ir--]);
        }
        if (abs(que.front()-a[il]) > abs(que.back()-a[il])) {
            que.push_front(a[il]);
        } else {
            que.push_back(a[il]);
        }
        long long res = 0;
        while (que.size() > 1) {
            long long t = que.front(); que.pop_front();
            res += abs(t - que.front());
            //cout << t << " ";
        }
        //cout << que.front() << endl;
        if (ans < res) ans = res;
        reverse(a.begin(), a.end());
    }
    
    cout << ans << endl;
    return 0;
}