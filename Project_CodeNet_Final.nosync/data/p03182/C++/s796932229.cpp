#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


struct segment_change {
    long long to_add;

    // TODO: make sure the default constructor is the identity segment_change.
    segment_change(long long _to_add = 0) : to_add(_to_add) {}

    void reset() {
        to_add = 0;
    }

    bool has_change() const {
        return to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    // TODO: make sure to check for sentinel values.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    long long maximum;

    // TODO: make sure the default constructor is the identity segment.
    segment(long long _maximum = numeric_limits<long long>::min()) : maximum(_maximum) {}

    void apply(int length, const segment_change &change) {
        maximum += change.to_add;
    }

    void join(const segment &other) {
        maximum = max(maximum, other.maximum);
    }

    // TODO: decide whether to re-implement this for better performance. Mainly relevant when segments contain arrays.
    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // O(n) initialization of our tree.
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void push_down(int position, int length) {
        if (!changes[position].has_change())
            return;

        if (2 * position < tree_n) {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a <= start && end <= b) {
            range_op(position, end - start);
            return;
        }

        if (position >= tree_n)
            return;

        push_down(position, end - start);
        int mid = (start + end) / 2;
        if (a < mid) process_range(2 * position, start, mid, a, b, needs_join, range_op);
        if (b > mid) process_range(2 * position + 1, mid, end, a, b, needs_join, range_op);
        if (needs_join) tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) {
        segment answer;

        process_range(1, 0, tree_n, a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        process_range(1, 0, tree_n, a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);
            if (position < tree_n) changes[position] = changes[position].combine(change);
        });
    }

    template<typename T_bool>
    int find_last_prefix(int n, T_bool &&should_join) {
        segment current;

        // Check edge cases.
        if (!should_join(current, current))
            return -1;

        if (should_join(current, tree[1]))
            return n;

        int position = 1;
        int start = 0, end = tree_n;

        while (position < tree_n) {
            int mid = (start + end) / 2;
            push_down(position, end - start);

            if (should_join(current, tree[2 * position])) {
                current.join(tree[2 * position]);
                position = 2 * position + 1;
                start = mid;
            } else {
                position = 2 * position;
                end = mid;
            }
        }

        assert(position == tree_n + start);
        assert(0 <= start && start < n);
        assert(end - start == 1);
        return start;
    }
};


const long long LL_INF = (long long) 2e18 + 5;

int N, M;
vector<vector<pair<int, int>>> starting_at, ending_at;
vector<long long> dp;

int main() {
    scanf("%d %d", &N, &M);
    starting_at.assign(N + 1, {});
    ending_at.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        int L, R, score;
        scanf("%d %d %d", &L, &R, &score);
        starting_at[L].emplace_back(R, score);
        ending_at[R].emplace_back(L, score);
    }

    dp.assign(N + 1, -LL_INF);
    dp[0] = 0;
    seg_tree tree(N + 1);
    tree.build(vector<segment>(N + 1, segment(0)));

    for (int i = 1; i <= N; i++) {
        for (pair<int, int> p : starting_at[i])
            tree.update(0, i, p.second);

        dp[i] = tree.query(0, i).maximum;
        tree.update(i, i + 1, segment_change(dp[i]));

        for (pair<int, int> p : ending_at[i])
            tree.update(0, p.first, -p.second);
    }

    printf("%lld\n", *max_element(dp.begin(), dp.end()));
}
