#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cassert>
#include <utility>
#include <vector>
// #include <atcoder/all>

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



int main(void){
    std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); 
    std::cout << std::fixed << std::setprecision(16);
    
    long long int n, X, M; std::cin >> n >> X >> M;
    std::vector<long long int> Sum(M, 0);
    std::vector<int> Pos(M, -1);
    int idx = 0; long long int S = 0;
    for(; idx < n; ++idx){
        if(Pos[X] != -1) break;
        Sum[X] = S;
        Pos[X] = idx;
        S += X;
        X = (X * X) % M;
    }
    long long int remain = n - idx;
    const int loop = idx - Pos[X];

    const long long int DS = S - Sum[X];


    const long long int K = remain / loop;
    long long int d = remain % loop;
    long long int res = S + DS * K;
    while(d--){
        res += X;
        X = (X * X) % M;
    }
    std::cout << res << '\n';




    

    return 0;
}