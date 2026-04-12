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
string S;
void input(){
    fast_io();
    cin >> N >> S;
}

char rev(char x){
    if(x=='S') return 'W';
    return 'S';
}

bool make(char init, char sec){
    string ans(N,'.');
    ans[0] = init;
    ans[1] = sec;
    for (int i = 1; i <= N; i++)
    {
        if(ans[i%N]=='S' && S[i%N]=='o'){
            ans[(i+1)%N] = ans[i-1];
        }
        else if(ans[i%N]=='S' && S[i%N]=='x'){
            ans[(i+1)%N] = rev(ans[i-1]);
        }
        else if(ans[i%N]=='W' && S[i%N]=='o'){
            ans[(i+1)%N] = rev(ans[i-1]);
        }
        else if(ans[i%N]=='W' && S[i%N]=='x'){
            ans[(i+1)%N] = (ans[i-1]);
        }
    }
    if(ans[0]==init && ans[1]==sec){
        cout << ans << endl;
        return true;
    }
    return false;
}

int solve(){
    if(make('S','S')) return 0;
    if(make('S','W')) return 0;
    if(make('W','S')) return 0;
    if(make('W','W')) return 0;
    cout << -1 << endl;
    
    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}