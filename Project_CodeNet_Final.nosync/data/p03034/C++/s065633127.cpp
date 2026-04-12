#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    
    int N; cin >> N;
    vector<int> s(N);
    rep(i, N)cin >> s[i];

    int step = N - 1, ans = 0;
    for(int i = 1; i <= step; i++){
        int tmp = 0;
        if(step % i == 0){
            for(int j = i; j <= step; j += i){
                int fr = j, ba = step - j;
                if(fr >= ba)break;
                chmax(ans, tmp += (s[fr] + s[ba]));
            }
        } else {
            for(int j = i; j <= step; j += i){
                int fr = j, ba = step - j;
                if(fr + i > step)break;
                chmax(ans, tmp += (s[fr] + s[ba]));
            }
        }
    }

    cout << ans << endl;
    return 0;

}