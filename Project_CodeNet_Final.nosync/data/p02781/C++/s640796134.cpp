#define DEBUG 1
#include <bits/stdc++.h>
#define loop(n) for (lint ngtkana_is_a_genius = 0; ngtkana_is_a_genius < lint(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (lint i = lint(begin); (i) < lint(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto&& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto&& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#if DEBUG
#define debug(...)\
    do {\
        std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
        debug_impl(__VA_ARGS__);\
        std::cerr << std::noboolalpha;\
    } while (false)
#else
#define debug(...) {}
#endif

int main() {
    std::cin.tie(0); std::cin.sync_with_stdio(false);
    std::string s; std::cin >> s;
    int n=s.length();
    int ans=0;
    int a=s.at(0)-'0';
    int k; std::cin >> k;
    if(k==1){
        std::cout << a+9*(n-1) << std::endl;
    }
    if(k==2){
        // 1 つ目が 1 以降
        ans+=(n-1)*(n-2)/2*9*9;
        // 1 つ目が 0 番目で、数字として小さい
        ans+=(a-1)*(n-1)*9;
        int j=1;
        while(j<n&&s.at(j)=='0')j++;
        if(j<n){
            int b=s.at(j)-'0';
            // 2 つ目が j+1 以降
            ans+=(n-1-j)*9;
            // 2 つ目が j 番目
            ans+=b;
        }
        std::cout << ans << std::endl;
    }
    if (k==3){
        // 1 つ目が 1 以降
        ans+=(n-1)*(n-2)*(n-3)/6*9*9*9;
        // 1 つ目が 0 番目で、数字として小さい
        ans+=(a-1)*(n-1)*(n-2)/2*9*9;

        int j=1;
        while(j<n&&s.at(j)=='0')j++;
        int k=j+1;
        while(k<n&&s.at(k)=='0')k++;
        if(j<n){
            int b=s.at(j)-'0';
            // 2 つ目が j+1 以降
            ans+=(n-1-j)*(n-2-j)/2*9*9;
            // 2 つ目が数字として小さい
            ans+=(b-1)*(n-1-j)*9;
        }
        if(k<n){
            int c=s.at(k)-'0';
            // 3 つ目が k+1 以降
            ans+=(n-1-k)*9;
            // 3 つ目が k 番目
            ans+=c;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}