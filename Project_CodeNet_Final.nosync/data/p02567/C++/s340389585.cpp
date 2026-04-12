#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cassert>
#include <utility>
#include <vector>
#include <atcoder/all>

template <class InputIterator>
std::ostream& range_output(std::ostream& os_arg, InputIterator first_arg, InputIterator last_arg){ if(first_arg != last_arg){ do{ os_arg << *(first_arg++); if(first_arg == last_arg) break; os_arg << ' '; } while(true); }  return os_arg; }
template <class Tp> std::ostream& operator << (std::ostream& os_arg, const std::vector<Tp>& arr_arg){ return range_output(os_arg, arr_arg.cbegin(), arr_arg.cend()); }
template <class Tp, std::size_t Size> std::ostream& operator << (std::ostream& os_arg, const std::array<Tp, Size>& arr_arg){ return range_output(os_arg, arr_arg.cbegin(), arr_arg.cend()); }
template <class S, class T> std::ostream& operator << (std::ostream& os_arg, const std::pair<S, T>& pair_arg){ return os_arg << '(' << pair_arg.first << ", " << pair_arg.second << ')'; }

#ifndef ONLINE_JUDGE
    template <typename Head> void dump_out(Head head_arg){ std::cerr << head_arg << '\n'; }
    template <typename Head, typename... Tail>
    void dump_out(Head head_arg, Tail... tail_args){ std::cerr << head_arg << ", "; dump_out(tail_args...); }
    #define dump(...) do { std::cerr << "[in line " << __LINE__ << "] " << #__VA_ARGS__ << " : "; dump_out(__VA_ARGS__); } while(false)
#else
    #define dump(...) (void(0))
#endif


constexpr int max(int a, int b){ return (a > b) ? a : b; }
constexpr int id(void){ return std::numeric_limits<int>::min(); }
using seg_tree_t = atcoder::segtree<int, max, id>;



int main(void){
    std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); 
    std::cout << std::fixed << std::setprecision(16);
    int n, q; std::cin >> n >> q;
    std::vector<int> A(n); for(auto& itr : A) std::cin >> itr;
    seg_tree_t ST(A);
    while(q--){
        char c; int x, y; std::cin >> c >> x >> y;
        if(c == '1') ST.set(x - 1, y);
        else if(c == '2') std::cout << ST.prod(x - 1, y) << '\n';
        else{
            const int r = ST.max_right(x - 1, [&](int v){ return v < y; });
            std::cout << r + 1 << '\n';
        }
    }

    return 0;
}