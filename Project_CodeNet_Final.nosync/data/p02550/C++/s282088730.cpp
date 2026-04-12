#include <bits/stdc++.h>
using namespace std;
// #define LOCAL // 提出時はコメントアウト
#define DEBUG_

typedef long long ll;
const double EPS = 1e-9;
const ll INF = ((1LL<<62)-(1LL<<31));
typedef vector<ll> vecl;
typedef pair<ll, ll> pairl;
template<typename T, typename U> using mapv = map<T,vector<U>>;

#define ALL(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define contains(S,x) find(ALL(S),x) != S.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> vector<vector<T>> genarr(ll n, ll m, T init) { return vector<vector<T>>(n,vector<T>(m,init)); }

///// DEBUG
#define DUMPOUT cerr
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
template<typename T>istream&operator>>(istream&is,vector<T>&vec){for(T&x:vec)is>>x;return is;}
template<typename T,typename U>ostream&operator<<(ostream&os,pair<T,U>&pair_var){os<<"("<<pair_var.first<<", "<<pair_var.second<<")";return os;}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&vec){os<<"{";for(int i=0;i<vec.size();i++){os<<vec[i]<<(i+1==vec.size()?"":", ");}
os<<"}";return os;}
template<typename T,typename U>ostream&operator<<(ostream&os,map<T,U>&map_var){os<<"{";repi(itr,map_var){os<<*itr;itr++;if(itr!=map_var.end())os<<", ";itr--;}
os<<"}";return os;}
template<typename T>ostream&operator<<(ostream&os,set<T>&set_var){os<<"{";repi(itr,set_var){os<<*itr;itr++;if(itr!=set_var.end())os<<", ";itr--;}
os<<"}";return os;}
void dump_func(){DUMPOUT<<endl;}
template<class Head,class...Tail>void dump_func(Head&&head,Tail&&...tail){DUMPOUT<<head;if(sizeof...(Tail)>0){DUMPOUT<<", ";}
dump_func(std::move(tail)...);}
#ifndef LOCAL
#undef DEBUG_
#endif
#ifdef DEBUG_
#define DEB
#define dump(...)                                                          \
DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
        << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
        << endl                                                            \
        << "    ",                                                         \
    dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

//////////

int main() {
    #ifdef LOCAL
    ifstream in("../../Atcoder/input.txt");
    cin.rdbuf(in.rdbuf());
    #endif

    ll N,X,M;
    cin>>N>>X>>M;

    unordered_set<ll> seen;
    vecl memo;
    ll x = X;

    seen.insert(X);
    memo.push_back(X);

    ll dup_i = 0;
    ll dup = 0;

    ll ans = X;
    if (N==1) {
        cout << ans << endl;
        return 0;
    }
    rep(i,N) {
        x = (x%M) * (x%M) % M;
        if (seen.count(x) > 0) {
            dup_i = memo.size();
            dup = x;
            break;
        }
        memo.push_back(x);
        seen.insert(x);
        ans += x;
        if (i == N-2) { // 重複なければ、そのまま答え
            cout << ans << endl;
            dump("normal");
            return 0;
        }
    }
    dump(memo);
    dump(dup_i,dup,ans);

    ll window = 0;
    ll dup_origin = 0;
    // ll window_sum = dup;
    vecl window_sum(memo.size()+10,0);
    // window_sum[1] = dup;
    ll window_i = 0;
    bool found = false;

    ans = 0;
    rep(i,memo.size()) {
        if (found) {
            // window_sum += memo[i];
            window_sum[window_i+1] += memo[i] + window_sum[window_i];
            window_i++;
            continue;
        }
        if (memo[i] == dup) {
            dup_origin = i;
            window = dup_i - i;
            found = true;
            window_sum[window_i+1] += memo[i] + window_sum[window_i];
            window_i++;
            continue;
        }
        ans += memo[i]; // window以外は先に足す
    }

    dump(dup_origin,ans);

    ll r = N-1 - (dup_origin - 1);
    ll ref_size = floor(r / window);
    ll over = r % window;

    ans += window_sum[window_i] * ref_size;
    dump(r,window,ref_size,ans);

    // ll over_count = 0;
    // REP(i,dup_origin,memo.size()) {
    //     if (over_count == over) break;
    //     ans += memo[i];
    //     over_count++;
    // }

    ans += window_sum[over];


    cout << ans << endl;



    return 0;
}
