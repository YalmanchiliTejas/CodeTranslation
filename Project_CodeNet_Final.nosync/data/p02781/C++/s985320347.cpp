#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } 
template <typename A>
string to_string(A v) {
    bool first = true; 
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}"; 
    return res;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    dbg_out(T...);
}
#ifdef LOCAL
    #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
    #define dbg(...) 42
#endif

#define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define MP make_pair
#define sz(v) ((int)(v).size())  
#define fr(i, j, k) for(int i = j; i < k; i++)
#define nl "\n"
typedef pair<int, int> pii;
typedef vector <int> vi;

pii dir[8] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1} , {-1, 1}, {1, -1} };

const int inf = (1LL << 60), mod = 1e9+7, nn = 2e5+5;

int ncr(int n, int r){
    r = min(r, n-r);
    int ans = 1;

    for(int i = 1; i <= r; i++){
        int h = __gcd(n-r+i, i);
        int x = (n-r+i)/h, y = i/h;
        ans *= x;
        ans /= y;
    }
    return ans;
}

void solve(){
    string s;
    int k;
    cin >> s >> k;
    int n = sz(s), ans = 0;
    int fir = s[0] - '0';

    fr(i, 1, n+1){
        if(i >= k){
            int here = 0;
            if(i < n) {
                here = 9 * ncr(i-1, k-1);
                fr(j, 0, k-1) here *= 9;
            }
            else {
                here = (fir-1) * ncr(i-1, k-1);
                fr(j, 0, k-1) here *= 9;

                // fill fir on first pos
                if(k == 3){
                    for(int x = 1; x < n; x++){
                        for(int y = x+1; y < n; y++){
                            for(int z = 1; z <= 9; z++){
                                for(int q = 1; q <= 9; q++){
                                    string t;
                                    fr(c, 0, n){
                                        if(c == 0) t += (fir + '0');
                                        else if(c == x) t += (z + '0');
                                        else if(c == y) t += (q + '0');
                                        else t += '0';
                                    }
                                    // dbg(t, s);
                                    if(t <= s) here++;
                                }
                            }
                        }
                    }
                }
                else if(k == 2){
                    for(int x = 1; x < n; x++){
                        for(int z = 1; z <= 9; z++){
                            string t;
                            fr(c, 0, n){
                                if(c == 0) t += (fir + '0');
                                else if(c == x) t += (z + '0');
                                else t += '0';
                            }
                            // dbg(t, s);
                            if(t <= s) here++;
                        }
                    }
                }
                else here++;
            }
            ans += here;
        }
        dbg(i, ans);
    }
    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}