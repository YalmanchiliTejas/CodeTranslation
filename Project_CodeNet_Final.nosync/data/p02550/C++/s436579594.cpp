#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct loop_info {
    lint loop_len;
    lint prefix_len;
    lint unit;
};

lint n, x, m;

lint f(lint z) {
    return z * z % m;
}

lint simple_solve(lint start, lint k) {
    lint now = start;
    lint res = 0;
    for (int i = 0; i < k; i++) {
        res += now;
        now = f(now);
    }
    return res;
}

loop_info get_loop() {
    vector<lint> appear_time(m, -1);
    lint now = x;
    lint time = 0;
    loop_info res;
    while (true) {
        if (appear_time[now] == -1) {
            appear_time[now] = time;
            time++;
            now = f(now);
        } else {
            res.loop_len = time - appear_time[now];
            res.prefix_len = appear_time[now];
            res.unit = simple_solve(now, res.loop_len);
            return res;
        }
    }
}

int main() {
    cin >> n >> x >> m;
    auto loop = get_loop();
    if (n < loop.prefix_len) {
        cout << simple_solve(x, n) << endl;
    } else {
        lint loop_num = (n - loop.prefix_len) / loop.loop_len;
        lint rem = n - loop_num * loop.loop_len;
        lint ans = simple_solve(x, rem) + loop.unit * loop_num;
        cout << ans << endl;
    }
}