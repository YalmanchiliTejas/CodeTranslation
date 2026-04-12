#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i & 1) dq.push_back(a);
        else dq.push_front(a);
    }
    if (n & 1) for (int i = 0; i < n; i++) cout << dq.front() << " \n"[i == n - 1], dq.pop_front();
    else  for (int i = 0; i < n; i++) cout << dq.back() << " \n"[i == n - 1], dq.pop_back();
    return 0;
}
