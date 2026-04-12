#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define x first
#define y second
#define ndl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)x.size()
#define bit __builtin_popcount
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using namespace __gnu_pbds;

template<typename T> using indexed_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<int, ull> piu;
typedef vector<vector<int>> matrix;

const ll INF = 1e18 + 123;
const ld EPS = 1e-9;
const int inf = 1e9 + 123;
const int MOD = 1e9 + 7;
const int N = 5e5 + 13;
const int M = 1e6 + 123;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

string n, s;

bool check(){
    if (sz(s) < sz(n)) return 1;
    for (int i = sz(n)-1; i >= 0; i--){
        if (n[i] > s[i]) break;
        if (n[i] < s[i]) return 0;
    }
    return 1;
}

int main(){
    #ifdef KAZAKH
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    reverse(all(n));
    int k;
    cin >> k;
    int l = sz(n);
    int ans = 0;
    if (k == 1){
        for (int i = 0; i < l; i++){
            s += "0";
            for (s[i] = '1'; s[i] <= '9'; s[i]++){
                ans += check();
                //if (check())cout<<s<<endl;
            }
            s[i] = '0';
        }
    }
    if (k == 2){
        for (int i = 0; i < l; i++){
            s += "0";
            for (s[i] = '1'; s[i] <= '9'; s[i]++){
                for (int j = 0; j < i; j++){
                    for (s[j] = '1'; s[j] <= '9'; s[j]++){
                        ans += check();
                    }
                    s[j] = '0';
                }
            }
            s[i] = '0';
        }
    }
    if (k == 3){
        s = "0";
        for (int i = 0; i < l-1; i++){
            ans += i * (i-1) / 2 * 9*9*9;
            s+="0";
        }
        for (s[l-1] = '1'; s[l-1] <= '9'; s[l-1]++){
            if (s[l-1] < n[l-1]){
                ans += (l-1) * (l-2) / 2 * 81;
                continue;
            }
            for (int i = 0; i < l-1; i++){
                for (s[i] = '1'; s[i] <= '9'; s[i]++){
                    for (int j = 0; j < i; j++){
                        for (s[j] = '1'; s[j] <= '9'; s[j]++){
                            ans += check();
                        }
                        s[j] = '0';
                    }
                }
                s[i] = '0';
            }
        }
    }
    cout << ans;
    return 0;
}
