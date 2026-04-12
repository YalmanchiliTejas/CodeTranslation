#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
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

int main(){
    int H, W;
    cin >> H >> W;
    string space[H];
    for(int i = 0; i < H; i++){
        cin >> space[i];
    }
    bool is_blank_row[H];
    for(int i = 0; i < H; i++){
        is_blank_row[i] = true;
        for(int j = 0; j < W; j++){
            is_blank_row[i] &= (space[i][j] == '.');
        }
    }
    bool is_blank_column[W];
    for(int i = 0; i < W; i++){
        is_blank_column[i] = true;
        for(int j = 0; j < H; j++){
            is_blank_column[i] &= (space[j][i] == '.');
        }
    }
    for(int i = 0; i < H; i++){
        if(is_blank_row[i]){
            continue;
        }
        for(int j = 0; j < W; j++){
            if(!is_blank_column[j]){
                cout << space[i][j];
            }
        }
        cout << endl;
    }
}
