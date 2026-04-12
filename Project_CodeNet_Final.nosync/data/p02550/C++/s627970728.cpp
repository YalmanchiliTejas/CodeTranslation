#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    set<ll> s;
    deque<ll> vec;
    ll a = x;
    ll sum = 0;
    ll loop_start;
    for (int i = 0; i <= m; i++) {
        if (s.count(a)) {
            loop_start = a;
            break;
        }
        s.insert(a);
        vec.push_back(a);
        sum += a;
        a = a * a % m;
    }

    ll ans = 0;
    if (s.count(0)) {
        ans = sum;
    }
    else {
        while (vec.front() != loop_start) {
            ans += vec.front();
            sum -= vec.front();
            vec.pop_front();
            n--;
        }
        ll loop = vec.size();
        ans += sum * (n / loop);
        for (int i = 0; i < n % loop; i++) {
            ans += vec[i];
        }
    }
    cout << ans << endl;
    return 0;
}