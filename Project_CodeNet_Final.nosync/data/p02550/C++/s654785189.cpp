#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct loop_info {
    lint loop_len;
    lint prefix_len;
    lint unit;
    loop_info() {}
    loop_info(lint l, lint p, lint u) : loop_len(l), prefix_len(p), unit(u) {}
};

lint n, x, m;

lint f(lint z) {
    return z * z % m;
}

loop_info get_loop() {
    vector<lint> appear_time(m, -1);
    lint now = x;
    lint time = 0;
    loop_info res;
    lint start_val;
    while (true) {
        if (appear_time[now] == -1) {
            appear_time[now] = time;
            time++;
            now = f(now);
        } else {
            res.loop_len = time - appear_time[now];
            res.prefix_len = appear_time[now];
            start_val = now;
            break;
        }
    }
    lint unit = 0;
    lint val = start_val;
    for (int i = 0; i < res.loop_len; i++) {
        unit += val;
        val = f(val);
    }
    res.unit = unit;
    return res;
}

lint simple_solve(lint k) {
    lint now = x;
    lint res = 0;
    for (int i = 0; i < k; i++) {
        res += now;
        now = f(now);
    }
    return res;
}

int main() {
    cin >> n >> x >> m;
    auto loop = get_loop();
    if (n < loop.prefix_len) {
        cout << simple_solve(n) << endl;
    } else {
        lint loop_num = (n - loop.prefix_len) / loop.loop_len;
        lint rem = n - loop_num * loop.loop_len;
        lint ans = simple_solve(rem) + loop.unit * loop_num;
        cout << ans << endl;
    }
}