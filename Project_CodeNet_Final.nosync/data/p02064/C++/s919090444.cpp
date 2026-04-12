#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << endl

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-8;

const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<typename T>
bool chmax(T& a, T b, bool equal = false){
    if(a < b || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b, bool equal = false){
    if(b < a || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

int query(int u, int v){
    cout << "? " << u << " " << v << endl;
    int res;
    cin >> res;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, s, t;
    cin >> n >> s >> t;

    int cost = query(s, t);

    vector<int> a(n + 1, 0), b(n + 1, 0);
    a[t] = cost;
    b[s] = cost;
    map< int, vector<int> > mp;
    reps(i, n){
        if(i == s || i == t){
            continue;
        }
        a[i] = query(s, i);
        b[i] = query(i, t);
        if(a[i] + b[i] == cost){
            mp[a[i]].emplace_back(i);
        }
    }
    mp[cost].emplace_back(t);

    vector<int> ans = {s};
    for(auto it = mp.begin() ; it != mp.end() ; ++it){
        for(auto x : (*it).second){
            int q = query(ans.back(), x);
            if(q == a[x] - a[ans.back()]){
                ans.emplace_back(x);
                break;
            }
        }
    }

    cout << '!';
    rep(i, ans.size()){
        cout << ' ' << ans[i];
    }
    cout << endl;

    return 0;
}
