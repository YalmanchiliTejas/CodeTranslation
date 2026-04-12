#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
const int MOD = 1000000007;
string dec(string s){
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '0'){
            s[i] = '9';
        }else{
            s[i] = s[i] - 1;
            if(i == 0 && s[i] == '0'){
                s = s.substr(1);
            }
            break;
        }
    }
    return s;
}
void add(int& x, int y){
    x = (x + y) % MOD;
}
int solve(string s, string t){
    const int MAX_N = 10010;
    const int MAX_L = 510;

    int n = s.size();
    int m = t.size();
    // printf("s = %s t = %s\n", s.c_str(), t.c_str());
    // printf("n = %d m = %d\n", n, m);

    int next[MAX_L][10] = {};
    for(int i = 0; i <= m; i++){
        for(int c = 0; c < 10; c++){
            string r = t.substr(0, i) + string(1, '0' + c);
            for(int len = r.size(); len >= 0; len--){
                if(r.substr(r.size() - len, len) == t.substr(0, len)){
                    next[i][c] = len;
                    break;
                }
            }
        }
    }

    static int count[MAX_N][MAX_L][2] = {};
    static int match[MAX_N][MAX_L][2] = {};
    memset(count, 0, sizeof(count));
    memset(match, 0, sizeof(match));
    for(int i = 0; i < n; i++){
        for(int c = (i + 1 < n ? 1 : 0); c <= (i == 0 ? s[i] - '0' : 9); c++){
            int nj = next[0][c];
            int nlw = (i > 0 || c < s[i] - '0');
            add(count[i + 1][nj][nlw], 1);
            if(nj == m){
                add(match[i + 1][nj][nlw], 1);
            }
        }
        for(int j = 0; j <= m; j++){
            for(int lw = 0; lw < 2; lw++){
                for(int c = 0; c <= (lw ? 9 : s[i] - '0'); c++){
                    int nj = next[j][c];
                    int nlw = lw || (c < s[i] - '0');
                    add(count[i + 1][nj][nlw], count[i][j][lw]);
                    add(match[i + 1][nj][nlw], match[i][j][lw]);
                    if(nj == m){
                        add(match[i + 1][nj][nlw], count[i][j][lw]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i++){
        add(ans, match[n][i][0]);
        add(ans, match[n][i][1]);
    }
    // printf("return %d\n", ans);
    return ans;
}
int main(){
    string a, b, c;
    while(cin >> a >> b >> c){
        int x = solve(b, c);
        int y = (a != "0" ? solve(dec(a), c) : 0);
        cout << (x - y + MOD) % MOD << endl;
    }
    return 0;
}