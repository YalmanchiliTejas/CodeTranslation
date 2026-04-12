#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;
typedef unsigned long long BITMASK; typedef long long ll; typedef long double ld;
#define has_bit(bit_mask, x) ((bit_mask) & (1ULL << (x)))
#define turn_on_bit(bit_mask, x) (bit_mask |= (1ULL << (x)))
#define turn_off_bit(bit_mask, x) (bit_mask &= (~(1ULL << (x))))
#define smallest_on_bit(bit_mask) (__builtin_ctzint((bit_mask) & (-(bit_mask))))
#define CLOCK_START clock_t chrono_clk_beg = clock()
#define CLOCK_END clock_t chrono_clk_end = clock(); cerr << (double(chrono_clk_end - chrono_clk_beg) / CLOCKS_PER_SEC) << " sec"
#define bug(args ...) cerr << __LINE__ << ">> ", err(new istringstream(string(#args)), args), cerr << '\n'
#define decToBin(name, num) string name = bitset<8>(num).to_string();
#define binToDec(name, binary) unsigned long name = bitset<8>(binary).to_ulong();
#define radToDeg(name, radians) double name = radians * 180 / M_PI;
#define all(x) x.begin(), x.end()
#define mapfind(mp, x) (mp.find(x) != mp.end())
#define arrfind(arr, x) (find(all(arr), x) != arr.end())
#define removeDuplicates(vec) sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define printMat(mat) for (auto &x : mat) { for (auto &y : x) cout << y << " "; cout << '\n'; }
#define printArr(arr) for (auto &x : arr) cout << x << " "; cout << '\n';
#define ceil(a, b) ((a+b-1)/b)
#define int ll
#define double ld
#define INF (1LL<<62)
#define M_PI 3.14159265358979323846
void err(istringstream *iss) {} template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) { string _name; *iss >> _name; if (_name.back()==',') _name.pop_back(); cerr << _name << " = " << _val << "; ", err(iss, args ...); }
void str_replaceAll(string& str, const string& from, const string& to) { if(from.empty()) return; size_t start_pos = 0; while((start_pos = str.find(from, start_pos)) != std::string::npos) { str.replace(start_pos, from.length(), to); start_pos += to.length(); } }
#define MOD 1000000007

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int dp[n][n];
    for (int i = 0; i < n; ++i) dp[i][i] = arr[i];
    for (int d = 1; d < n; ++d)
        for (int i = 0, j = d; j < n; ++i, ++j)
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
    cout << dp[0][n-1] << '\n';
    return 0;
}