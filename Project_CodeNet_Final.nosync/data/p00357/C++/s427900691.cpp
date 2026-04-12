#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<class like_bool> inline void YES(like_bool condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class like_bool> inline void Yes(like_bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class like_bool> inline void POSS(like_bool condition){ if(condition) cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl; }
template<class like_bool> inline void Poss(like_bool condition){ if(condition)cout << "Possible" << endl; else cout << "Impossible" << endl; }
template<class like_bool> inline void First(like_bool condition){ if(condition)cout << "First" << endl; else cout << "Second" << endl; }
int character_count(string text, char character){ int ans = 0; for(int i = 0; i < text.size(); i++){ ans += (text[i] == character); } return ans; }
long power(long base, long exponent, long module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ long root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position move_pattern[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++){ ans += to_string(*i) + " "; } ans.pop_back(); cout << ans << endl; }
long gcd(long a, long b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }}
#define mod long(1e9 + 7)
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcount(n)

bool judge(int N, int trampoline[]){
    int can_go_rightmost = 0;
    for(int i = 0; i <= can_go_rightmost && can_go_rightmost < N; i++){
        can_go_rightmost = max(can_go_rightmost, i + trampoline[i] / 10);
    }
    return can_go_rightmost >= N;
}

int main(){
    int N;
    cin >> N;
    int trampoline[N];
    for(int i = 0; i < N; i++){
        cin >> trampoline[i];
    }
    if(!judge(N, trampoline)){
        cout << "no" << endl;
        return 0;
    }
    reverse(trampoline, trampoline + N);
    if(judge(N, trampoline)){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}


