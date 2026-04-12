#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <assert.h>
using namespace std;
#define mod (long)(1e9 + 7)
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl(long(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzl(x))
#define long long long
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void POSS(T condition){ if(condition) cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl; }
template<class T> inline void Poss(T condition){ if(condition) cout << "Possible" << endl; else cout << "Impossible" << endl; }
template<class T> inline void First(T condition){ if(condition) cout << "First" << endl; else cout << "Second" << endl; }
template<class T = string, class U = char>int character_count(T text, U character){ int ans = 0; for(U i: text){ ans += (i == character); } return ans; }
long power(long base, long exponent, long module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ long root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position move_pattern[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++){ ans += to_string(*i) + " "; } ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }} template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<long> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } long C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

string K;
int D;

long dp[12121][2][121];

long find(int now, bool is_less, int surplus){
    if(now == K.size()){
        return surplus == 0;
    }else if(dp[now][is_less][surplus] != -1){
        return dp[now][is_less][surplus];
    }
    if(is_less){
        long ans = 0;
        for(int i = 0; i <= 9; i++){
            ans += find(now + 1, true, (surplus + i) % D);
        }
        return dp[now][is_less][surplus] = ans % mod;
    }else{
        long ans = 0;
        for(int i = 0; i < K[now] - '0'; i++){
            ans += find(now + 1, true, (surplus + i) % D);
        }
        ans += find(now + 1, false, (surplus + K[now] - '0') % D);
        return dp[now][is_less][surplus] = ans % mod;
    }
}

int main(){
    cin >> K >> D;
    memset(dp, -1, sizeof(dp));
    cout << (find(0, false, 0) + mod - 1) % mod << endl;
}
