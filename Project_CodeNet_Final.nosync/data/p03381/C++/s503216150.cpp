#include <bits/stdc++.h>
#define show(x) cerr << #x << " = " << x << endl
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll MOD = 1000000007LL;
template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;
template <typename Functor>
struct fix_type
{
    Functor functor;
    template <typename... Args>
    decltype(auto) operator()(Args&&... args) const& { return functor(functor, std::forward<Args>(args)...); }
};
template <typename Functor>
fix_type<typename std::decay<Functor>::type> fix(Functor&& functor) { return {std::forward<Functor>(functor)}; }

int main()
{
    int N;
    cin >> N;
    vector<ll> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    auto x = X;
    sort(x.begin(), x.end());
    const ll left = x[N / 2 - 1];
    const ll right = x[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] <= left) {
            cout << right << endl;
        } else {
            cout << left << endl;
        }
    }

    return 0;
}
