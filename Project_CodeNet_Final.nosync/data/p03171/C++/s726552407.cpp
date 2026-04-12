#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &out, std::vector<T> const &cont) {
    for (auto &i : cont) {
        out << i << ' ';
    }
    return out;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, std::pair<T1, T2> const &p) {
    out << '{' << p.first << ", " << p.second << "}";
    return out;
}
#define imie(...) __debug_print(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __debug_print(const char *name, Arg1 &&arg1) {
#ifdef LOCAL
    cerr << "[" << name << ": " << arg1 << "]" << endl;
#endif
}
template <typename Arg1, typename... Args>
void __debug_print(const char *names, Arg1 &&arg1, Args &&... args) {
#ifdef LOCAL
    const char *comma = strchr(names + 1, ',');
    cerr << "[";
    cerr.write(names, comma - names) << ": " << arg1 << "],  ";
    __debug_print(comma + 2, args...);
#endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int64_t arr[N];
    for(auto& i : arr) cin >> i;
    int64_t DP[N][N];
    for(int l = N-1; l >= 0; --l){
        for(int r = l; r < N; ++r){
            if(l == r){
                DP[l][r] = arr[l];
            }
            else{
                DP[l][r] = max(arr[l] - DP[l+1][r], arr[r] - DP[l][r-1]);
            }
        }
    }
    cout << DP[0][N-1] << endl;
}