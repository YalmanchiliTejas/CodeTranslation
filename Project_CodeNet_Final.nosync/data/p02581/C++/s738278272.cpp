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

inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const deque<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for (auto el : v) cout << el << " "; return os; }

int N;
vector<int> A;
void input(){
    fast_io();
    cin >> N;
    for (int i = 0; i < 3*N; i++)
    {
        int a; cin >> a;
        A.push_back(a);
    }
}

vector<vector<int> > dp;
vector<int> dp_maxk;
int dp_max;

inline void chmax(int &a, const int& b){if(a<b) a=b;}

inline void update_rc(int x, int y, int z){
    if(x<y) swap(x,y);
    chmax(dp_maxk[x], z);
    chmax(dp_maxk[y], z);
    chmax(dp_max, z);
    // if(z <= dp[x][y]) return;
    chmax(dp[x][y], z);
    return;
}

inline void update(int x, int y, int z){
    if(x<y) swap(x,y);
    chmax(dp[x][y], z);
    // if(z <= dp[x][y]) return;
    // chmax(dp_maxk[x], z);
    // chmax(dp_maxk[y], z);
    // chmax(dp_max, z);
    return;
}

int solve(){
    // vector<map<int, map<int, int> > > dp;
    // dp.resize(N+1);
    dp.assign(N+1,vector<int>(N+1,-1e7));
    dp_maxk.assign(N+1,-1e7);
    if(A[0] < A[1]) swap(A[0], A[1]);
    dp[A[0]][A[1]] = 0;
    dp_max = 0;
    int add_all = 0;
    dp_maxk[A[0]] = 0;
    dp_maxk[A[1]] = 0;
    for(int i = 1; i < N; i++){
        if(A[3*i-1]==A[3*i] && A[3*i]==A[3*i+1])
        {
            // 全部一致
            add_all++;
        }
        else if(A[3*i-1]==A[3*i] || A[3*i]==A[3*i+1] || A[3*i+1]==A[3*i-1])
        {
            // 二つ一致
            int p, q;
            if(A[3*i-1]==A[3*i]){
                p = A[3*i-1];
                q = A[3*i+1];
            }
            else if(A[3*i]==A[3*i+1]){
                p = A[3*i];
                q = A[3*i-1];
            }
            else if(A[3*i+1]==A[3*i-1]){
                p = A[3*i+1];
                q = A[3*i];
            }
            // 下準備
            int dqq = dp[q][q] + 1; 
            vector<int> dpk(N+1,0);
            for (int k = 1; k <= N; k++)
            {
                if(p>k) dpk[k] = dp[p][k] + 1;
                else dpk[k] = dp[k][p] + 1;
            }

            // 以前のやつ一個だけ採用
            for (int k = 1; k <= N; k++)
            {
                update(k, q , dp_maxk[k]);
                update(k, p , dp_maxk[k]);
            }
            // 以前のやつを採用しない
            update_rc(p, p, dp_max);
            update_rc(p, q, dp_max);
            // pk,qppからpppを取った場合
            for (int k = 1; k <= N; k++)
            {
                update_rc(k, q, dpk[k]);
            }
            // qq,qppの場合
            update_rc(p, p, dqq);
        }
        else
        {
            // 全部ばらばら
            int p, q, r;
            p = A[3*i-1];
            q = A[3*i];
            r = A[3*i+1];
            // 下準備
            int dpp = dp[p][p] + 1;
            int dqq = dp[q][q] + 1;
            int drr = dp[r][r] + 1;
            // 以前のやつ一個だけ採用
            for(int k = 1; k<=N; k++){
                update(p, k, dp_maxk[k]);
                update(q, k, dp_maxk[k]);
                update(r, k, dp_maxk[k]);
            }
            // 以前のやつを採用しない
            update_rc(p, q, dp_max);
            update_rc(q, r, dp_max);
            update_rc(r, p, dp_max);
            // +1がある.pp,pqr or qq,pqr or rr,pqr
            update_rc(q, r, dpp);
            update_rc(p, r, dqq);
            update_rc(p, q, drr);
        }
    }
    int ans = dp_max;
    int last = A[3*N-1];
    chmax(ans, dp[last][last] + 1);
    cout << (ans + add_all) << "\n";
    return 0;
} 

int main()
{
    input();
    solve();
    return 0;
}