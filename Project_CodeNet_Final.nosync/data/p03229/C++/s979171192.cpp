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
vector<ll> A;
void input(){
    fast_io();
    cin >> N;
    A = fetch_vec<ll>(N);
}

int solve(){
    sort(A.begin(),A.end());
    ll ans = 0;
    if(N%2){
        ll tmp = 0;
        for (int i = (N+1)/2; i < N; i++)
        {
            tmp += 2*A[i];
        }
        for (int i = 0; i < (N+1)/2; i++)
        {
            tmp -= 2*A[i];
        }
        tmp += A[(N-3)/2];
        tmp += A[(N-1)/2];
        ans = max(ans,tmp);

        tmp = 0;
        for (int i = (N-1)/2; i < N; i++)
        {
            tmp += 2*A[i];
        }
        for (int i = 0; i < (N-1)/2; i++)
        {
            tmp -= 2*A[i];
        }
        tmp -= A[(N+1)/2];
        tmp -= A[(N-1)/2];
        ans = max(ans,tmp);
    }
    else{
        ll tmp = 0;
        for (int i = N/2; i < N; i++)
        {
            tmp += 2*A[i];
        }
        for (int i = 0; i < N/2; i++)
        {
            tmp -= 2*A[i];
        }
        tmp -= A[N/2];
        tmp += A[N/2-1];
        ans = max(ans,tmp);
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