#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

namespace chrono = std::chrono;
using namespace std::literals;

[[gnu::constructor]]
void fast_iostream() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
}
template <typename T, T Mod>
class zmod {
public:
    using number = T;
    static constexpr number mod = Mod;

    class valid_tag_t {};
    static valid_tag_t valid_tag;

    zmod() : m_value(0) {}

    zmod(number n) 
        : m_value(n)
    {
        m_value %= mod;
        if (m_value < 0) {
            m_value += mod;
        }
    }

    zmod(number n, valid_tag_t)
        : m_value(n)
    {}

    static zmod valid(number n) {
        return zmod(n, valid_tag);
    }

    zmod operator-() const noexcept {
        number value = mod - m_value;
        if (value == mod) {
            value = 0;
        }
        return zmod{value, valid_tag};
    }

    zmod inverse() const noexcept {
        return zmod{powmod(m_value, mod - 2), valid_tag};
    }

    zmod& operator+=(zmod other) noexcept {
        m_value += other.m_value;
        if (m_value >= mod){
            m_value -= mod;
        }
        return *this;
    }

    zmod& operator-=(zmod other) noexcept {
        return *this += -other;
    }

    zmod& operator *= (zmod other) noexcept {
        m_value = (m_value * other.m_value) % mod;
        return *this;
    }

    zmod& operator /= (zmod other) noexcept {
        return *this *= other.inverse();
    }

    number value() const noexcept {
        return m_value;
    }

private:
    static number powmod(number a, number x) {
        number result = 1;
        while (x > 0) {
            if (x % 2 == 1) {
                result = (result * a) % mod;
                x -= 1;
            } else {
                a = (a * a) % mod;
                x /= 2;
            }
        }
        return result;
    }

private:
    number m_value;
};

#define DEFINE_ZMOD_OPERATORS(OP, EQ_OP)                        \
    template <typename T, T mod, typename U>                    \
    zmod<T, mod> operator OP (U u, zmod<T, mod> v) {            \
        return zmod<T, mod>(u) EQ_OP v;                         \
    }                                                           \
    template <typename T, T mod, typename U>                    \
    zmod<T, mod> operator OP (zmod<T, mod> u, U v) {            \
        return u EQ_OP v;                                       \
    }                                                           \
    template <typename T, T mod>                                \
    zmod<T, mod> operator OP (zmod<T, mod> u, zmod<T, mod> v) { \
        return u EQ_OP v;                                       \
    }                                                           \

DEFINE_ZMOD_OPERATORS(+, +=)
DEFINE_ZMOD_OPERATORS(-, -=)
DEFINE_ZMOD_OPERATORS(*, *=)
DEFINE_ZMOD_OPERATORS(/, /=)

#undef DEFINE_ZMOD_OPERATORS

#define DEFINE_ZMOD_VALUE_OPERATORS(RET_TYPE, OP)                   \
    template <typename T, T mod, typename U>                        \
    RET_TYPE operator OP (zmod<T, mod> u, U v) {                    \
        return u.value() OP zmod<T, mod>(v).value();                \
    }                                                               \
    template <typename T, T mod, typename U>                        \
    RET_TYPE operator OP (U u, zmod<T, mod> v) {                    \
        return zmod<T, mod>(v).value() OP v.value();                \
    }                                                               \
    template <typename T, T mod>                                    \
    RET_TYPE operator OP (zmod<T, mod> u, zmod<T, mod> v) {         \
        return u.value() OP v.value();                              \
    }                                                               \

DEFINE_ZMOD_VALUE_OPERATORS(bool, ==)
DEFINE_ZMOD_VALUE_OPERATORS(bool, !=)

#undef DEFINE_ZMOD_VALUE_OPERATORS

template <typename T, T mod>
std::ostream& operator<<(std::ostream& os, zmod<T, mod> u) {
    return os << u.value();
}

using lmod7 = zmod<long long, 1000 * 1000 * 1000 + 7>;
using lmod9 = zmod<long long, 1000 * 1000 * 1000 + 9>;

#define WHATIS(expr) #expr << " = " << (expr)

constexpr long long inf = std::numeric_limits<long long>::max();

struct edge {
    int from;
    int to;
    long long d;

    edge() {}
    edge(int from, int to, long long d): from(from), to(to), d(d) {}
};

std::vector<std::vector<edge>> g;

void fill_dist(int n, int s, std::vector<long long>& dist) {
    dist.assign(n, inf);
    std::priority_queue<std::pair<long long, int>> q;
    q.emplace(0, s);
    dist[s] = 0;
    while (!q.empty()) {
        int cur; long long d;
        std::tie(d, cur) = q.top();
        q.pop();
        d = -d;
        if (d != dist[cur]) continue;
        for (edge next: g[cur]) {
            if (dist[next.to] > d + next.d) {
                dist[next.to] = d + next.d;
                q.emplace(-dist[next.to], next.to);
            }
        }
    }
}

void fill_number(int n, int s, std::vector<long long>& dist, 
                 std::vector<std::vector<int>>& rg,
                 std::vector<lmod7>& num) 
{
    num.assign(n, 0);
    num[s] = 1;
    std::vector<int> vs(n);
    std::iota(vs.begin(), vs.end(), 0);
    std::sort(vs.begin(), vs.end(), [&dist](int v, int u) { return dist[v] < dist[u]; });
    for (int v: vs) {
        if (dist[v] == inf) break;
        for (edge next: g[v]) {
            if (dist[next.to] != dist[v] + next.d) continue;
            num[next.to] += num[next.from];
            rg[next.to].push_back(next.from);
        }
    }
}

void fill_inf(int n, int t,
              std::vector<std::vector<int>>& rg,
              std::vector<lmod7>& num,
              std::vector<long long>& dist) 
{
    std::vector<char> used(n, false);
    std::queue<int> q;
    q.push(t);
    used[t] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next: rg[cur]) {
            if (used[next]) continue;
            used[next] = true;
            q.push(next);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dist[i] = inf;
            num[i] = 0;
        }
    }
}

lmod7 result = 0;
lmod7 all1 = 0;

void count_paths(int n, int s,
                 const std::vector<long long>& dist1, const std::vector<long long>& dist2,
                 const std::vector<lmod7>& num1, const std::vector<lmod7>& num2)
{
    std::vector<int> vs(n);
    std::iota(vs.begin(), vs.end(), 0);
    std::sort(vs.begin(), vs.end(), [&dist1](int v, int u) { return dist1[v] < dist1[u]; });
    for (int v: vs) {
        if (dist1[v] == inf) break;
        if (dist1[v] == dist2[v]) {
            cerr << "c on " << v + 1 << endl;
            lmod7 from = num1[v] * num2[v];
            lmod7 to = num2[s] - num2[v] * num1[v];
            result += from * to;
            all1 += from;
        }
        for (edge next: g[v]) {
            if (dist1[next.to] == inf) continue;
            if (dist1[next.to] != dist1[v] + next.d) continue;
            if (std::abs(dist1[next.from] - dist2[next.to]) < next.d) {
                cerr << "c on " << next.from + 1 << ' ' << next.to + 1 << endl;
                lmod7 from = num1[next.from] * num2[next.to];
                lmod7 to = num2[s] - num2[next.to] * num1[next.from];
                result += from * to;
                all1 += from;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    int m; cin >> m;
    int s; cin >> s; --s;
    int t; cin >> t; --t;
    g.resize(n);
    while (m--) {
        int u; cin >> u; --u;
        int v; cin >> v; --v;
        long long d; cin >> d;
        g[v].emplace_back(v, u, d);
        g[u].emplace_back(u, v, d);
    }

    std::vector<long long> dist1;
    std::vector<long long> dist2;
    std::vector<lmod7> num1;
    std::vector<lmod7> num2;

    std::vector<std::vector<int>> rg1(n);
    std::vector<std::vector<int>> rg2(n);

    fill_dist(n, s, dist1);
    fill_dist(n, t, dist2);
    fill_number(n, s, dist1, rg1, num1);
    fill_number(n, t, dist2, rg2, num2);

    fill_inf(n, t, rg1, num1, dist1);
    fill_inf(n, s, rg2, num2, dist2);

    for (int i = 0; i < n; ++i) {
        cerr << "dist[" << i + 1 << "] = " << dist1[i] << endl;
    }

    count_paths(n, s, dist1, dist2, num1, num2);

    assert(num1[t] == all1);

    cout << result << endl;
}
