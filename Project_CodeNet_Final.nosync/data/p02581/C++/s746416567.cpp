#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<58);

template<class T> bool chmin(T &a, const T &b){
    if(a > b) {a = b; return true;}
    else return false;
}
template<class T> bool chmax(T &a, const T &b){
    if(a < b) {a = b; return true;}
    else return false;
}

void input(vec &a){
    cin>>N;
    a.resize(N * 3);
    rep(i, N * 3) {cin>>a[i]; --a[i];}
}

int solver(vec a){
    rep(i, N - 1) sort(a.begin() + i * 3 + 2, a.begin() + i * 3 + 5);
    mat dp(N, vec(N, 0));
    vec memo(N, 0);
    int base = N * 10;
    dp[a[0]][a[1]] = dp[a[1]][a[0]] = memo[a[0]] = memo[a[1]] = base;
    for(int i = 2; i + 2 < N * 3; i += 3){
        if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
            --base;
            continue;
        }
        vec temp(0); // (score * N + x) * N + y
        // swap one
        rep(k, 3) rep(x, N) temp.push_back((memo[x] * N + x) * N + a[i + k]);
        // swap two
        ll m = *max_element(ALL(memo));
        rep(k, 3) temp.push_back((m * N + a[i + k]) * N + a[i + (k + 1) % 3]);
        // use one
        if(a[i + 1] == a[i + 2]) swap(a[i], a[i + 2]);
        if(a[i] == a[i + 1]){
            rep(x, N){
                temp.push_back(((dp[a[i]][x] + 1) * N + x) * N + a[i + 2]);
            }
        }
        //use two
        rep(k, 3) temp.push_back(((dp[a[i + k]][a[i + k]] + 1) * N + a[i + (k + 1) % 3]) * N + a[i + (k + 2) % 3]);
        int x, y;
        ll score;
        for(ll q : temp){
            y = q % N;
            q /= N;
            x = q % N; score = q / N;
            chmax(dp[x][y], score);
            chmax(dp[y][x], score);
            chmax(memo[x], score);
            chmax(memo[y], score);
        }
    }
    int ans = 0, ml = *a.rbegin();
    rep(i,N) chmax(ans, (int)*max_element(ALL(dp[i])));
    chmax(ans, (int)dp[ml][ml] + 1);
    return ans - base;
}

int greedy_solver(vec a){return 0;}

void rand_make(vec &a, uniform_int_distribution<> &rand10, uniform_int_distribution<> &randINF, mt19937 &mt){
    N = rand10(mt);
    a.resize(N * 3);
    rep(i, N * 3) {
        a[i] = randINF(mt) % N;
    }
}

void run_debug(vec &a, int max_n = 3){
    int ans(0), ans2(0);
    random_device seed;
    mt19937 mt(seed());
    uniform_int_distribution<> rand10(1, max_n), randINF(0, (int)1e+9);
    int num = (int)1e+5;
    while(ans == ans2 && (--num)){
        rand_make(a, rand10, randINF, mt);
        ans = solver(a);
        ans2 = greedy_solver(a);
    }
    cout<<N<<endl;
    rep(i, N * 3) cout<<a[i] + 1<<" \n"[i == N * 3 - 1];
    cout<<ans<<endl;
    cout<<ans2<<endl;
}

int main() {
    vec a;
    //run_debug(a, 4);
    input(a);
    cout<<solver(a)<<endl;
}