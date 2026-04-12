#include <bits/stdc++.h>
#ifdef __DEBUG__
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
#else
    #define DBG(X)
    #define SAY(X)
#endif

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[]={1, 0, -1, 0, 1,-1, 1,-1};
int dy[]={0, 1, 0, -1, 1, 1,-1,-1};
const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);

inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const deque<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

int N;
vector<map<char,int>> S;
void input(){
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        map<char,int> cnt;
        for (int i = 0; i < s.length(); i++)
        {
            cnt[s[i]]++;
        }
        S.push_back(cnt);
    }
    
}

int solve(){
    map<char,int> cnt;
    string ans;
    for (char c = 'a'; c <= 'z'; c++)
    {
        cnt[c] = 1e6;
        for (int i = 0; i < S.size(); i++)
        {
            cnt[c] = min(cnt[c],S[i][c]);
        }
        ans += string(cnt[c],c);
    }
    cout << ans << endl;   

    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}