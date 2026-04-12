#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

/* ...o(^-^)o... */
vector<int> to[8];
bool exist(vector<int> &vec, int val){
    rep(i, vec.size()){
        if(vec[i] == val) return true;
    }
    return false;
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b); to[b].push_back(a);
    }

    vector<int> per; int ans = 0;
    rep(i, n-1) per.push_back(i+1);
    do{
        if(!exist(to[0], per[0])) continue;
        bool ok = true;
        rep(i, n-2){
            if(!exist(to[per[i]], per[i+1])){
                ok = false; break;
            }
        }
        if(ok) ans++;
    }while(next_permutation(per.begin(), per.end()));

    out(ans);
}