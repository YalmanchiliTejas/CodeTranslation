#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;
typedef unsigned long long BITMASK; typedef long long ll; typedef long double ld;
#define has_bit(bit_mask, x) ((bit_mask) & (1Uint << (x)))
#define turn_on_bit(bit_mask, x) (bit_mask |= (1Uint << (x)))
#define turn_off_bit(bit_mask, x) (bit_mask &= (~(1Uint << (x))))
#define smallest_on_bit(bit_mask) (__builtin_ctzint((bit_mask) & (-(bit_mask))))
#define CLOCK_START clock_t chrono_clk_beg = clock()
#define CLOCK_END clock_t chrono_clk_end = clock(); cerr << (double(chrono_clk_end - chrono_clk_beg) / CLOCKS_PER_SEC) << " sec"
#define bug(args ...) cerr << __LINE__ << ">> ", err(new istringstream(string(#args)), args), cerr << '\n'
#define all(x) x.begin(), x.end()
#define mapfind(mp, x) (mp.find(x) != mp.end())
#define removeDuplicates(vec) sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define int ll
#define double ld
void err(istringstream *iss) {} template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) { string _name; *iss >> _name; if (_name.back()==',') _name.pop_back(); cerr << _name << " = " << _val << "; ", err(iss, args ...); }
#define MOD 1000000007

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (n == m) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}