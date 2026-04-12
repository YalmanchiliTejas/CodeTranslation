#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int MAX_INT = 2000000000;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.first,", ",x.second,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
 
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;
 
#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush



struct ball {
    int bag_idx;
    int ball_idx;
    int value;

    friend ostream& operator<<(ostream& os, const ball& b) {
        os << "{" << b.bag_idx << ", " << b.ball_idx << ", " << b.value << "}";
        return os;
    }
};


struct bag {
    int a;
    int b;

    int a_gidx;
    int b_gidx;

    friend ostream& operator<<(ostream& os, const bag& b) {
        os << "{" << b.a << ", " << b.b << ", " << b.a_gidx << ", " << b.b_gidx << "}";
        return os;
    }
};

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int N;
    cin >> N;
 
    vector<bag> bags(N);
    vector<ball> balls(2 * N);
    long long initial_product;
    int global_min = MAX_INT;
    int global_max = 0;
    int largest_red = 0;
    int smallest_blue = MAX_INT;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        bags[i] = a < b ? bag{a, b} : bag{b, a};

        int lower = bags[i].a;
        int upper = bags[i].b;

        largest_red = max(largest_red, lower);
        smallest_blue = min(smallest_blue, upper);

        global_min = min(global_min, lower);
        global_max = max(global_max, upper);

        balls[2 * i] = ball{i, 0, bags[i].a};
        balls[2 * i + 1] = ball{i, 1, bags[i].b};
    }
    initial_product = (long long)(global_max - smallest_blue) * (long long)(largest_red - global_min);

    sort(
        balls.begin(),
        balls.end(),
        [](ball b1, ball b2) { return b1.value < b2.value; }
    );
    for (int i = 0; i < balls.size(); i++) {
        int bag_idx = balls[i].bag_idx;
        if (balls[i].ball_idx) {
            bags[bag_idx].b_gidx = i;
        }
        else {
            bags[bag_idx].a_gidx = i;
        }
    }

    map<int, int> blues;
    map<int, int> reds;
    int global_max_idx = balls[2 * N - 1].bag_idx;
    int global_min_idx = balls[0].bag_idx;
    if (global_min_idx == global_max_idx) {cout << initial_product; return 0;}
    blues[global_max_idx] = 1;
    reds[global_max_idx] = 0;

    blues[global_min_idx] = 0;
    reds[global_min_idx] = 1;

    map<int, int> reds2 = reds;
    int r_max_idx_bound;
    for (int i = 2 * N - 2; i > 0; i--) {
        ball bal = balls[i];
        if (reds2.count(bal.bag_idx)) {
            r_max_idx_bound = i;
            break;
        }
        reds2[bal.bag_idx] = bool(bal.ball_idx);
    }

    int cur_r_min;
    for (int i = 1; i < 2 * N; i++) {
        int bag_idx = balls[i].bag_idx;
        if (reds.count(bag_idx)) {
            cur_r_min = i;
            break;
        }
        reds[bag_idx] = 1;
        blues[bag_idx] = 0;
    }
    int smallest_diff = MAX_INT;
    // pd(balls);
    // pd(r_max_idx_bound);
    for (int i = 2 * N - 2; i >= r_max_idx_bound; i--) {
        int bag_idx = balls[i].bag_idx;
        if (!reds.count(bag_idx)) {
            reds[bag_idx] = 1;
            blues[bag_idx] = 0;
        }
        // pd(reds);
        // pd(blues);
        smallest_diff = min(smallest_diff, balls[i].value - balls[cur_r_min].value);

        // pd(cur_r_min);
        if (i == r_max_idx_bound) break;
        cur_r_min = min(cur_r_min, bags[bag_idx].a_gidx);
        blues[bag_idx] = 1;
        reds[bag_idx] = 0;
    }
    long long new_product = (long long)smallest_diff * (long long)(global_max - global_min);

    cout << min(initial_product, new_product) << "\n";

    return 0;
}

