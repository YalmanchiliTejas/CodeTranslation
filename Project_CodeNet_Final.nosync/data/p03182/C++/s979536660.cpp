#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, score;
};

class SegmentTree {
  public:
    SegmentTree(int size):
        m_size(size),
        m_add(size * 2, 0),
        m_max(size * 2, 0) {}

    void add(int from, int to, int64_t value) {
        for (int l = from + m_size, r = to + m_size; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                m_max[l] += value;
                m_add[l++] += value;
            }
            if (r & 1) {
                m_add[--r] += value;
                m_max[r] += value;
            }
        }
        build(from + m_size);
        build(to + m_size - 1);
    }

    int64_t query() const {
        return m_max[1];
    }

  private:
    void build(int position) {
        while (position > 1) {
            position /= 2;
            m_max[position] = max(m_max[position * 2], m_max[position * 2 + 1]) + m_add[position];
        }
    }

    int m_size;
    vector<int64_t> m_add, m_max;
};

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    vector< vector<Interval> > intervals(N);
    for (int i = 0; i < M; ++i) {
        int L, R, W; cin >> L >> R >> W;
        --L; --R;
        intervals[R].emplace_back(Interval{L, W});
    }

    vector<int64_t> dp(N, 0);
    SegmentTree S(N);
    for (int i = 0; i < N; ++i) {
        dp[i] = S.query();

        S.add(i, i + 1, dp[i]);
        for (auto &interval : intervals[i])
            S.add(interval.start, i + 1, interval.score);
    }

    cout << max(S.query(), int64_t(0)) << "\n";
}
