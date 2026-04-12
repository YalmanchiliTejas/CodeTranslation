#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
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
#define mod long(1e9 + 7)
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl(long(n))
#define fcout cout << fixed << setprecision(10)
#define highest(x) (63 - __builtin_clzl(x))

long burger_size(int now){
    if(now == 0){
        return 1;
    }else{
        return burger_size(now - 1) * 2 + 3;
    }
}

int main(){
    int N;
    long X;
    cin >> N >> X;
    long ans = 0;
    for(int i = N; i >= 0; i--){
        if(i == 0){
            ans++;
            break;
        }
        if(X <= 1){
            break;
        }else if(X <= 1 + burger_size(i - 1)){
            X -= 1;
        }else if(X <= 1 + burger_size(i - 1) + 1){
            ans += power(2, i, 1e18);
            break;
        }else if(X <= 1 + burger_size(i - 1) + 1 + burger_size(i - 1)){
            ans += power(2, i, 1e18);
            X -= 1 + burger_size(i - 1) + 1;
        }else{
            ans += power(2, i, 1e18) + power(2, i, 1e18) - 1;
            break;
        }
    }
    cout << ans << endl;
}
