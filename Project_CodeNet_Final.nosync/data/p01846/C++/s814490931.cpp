#include <bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    for(string S; cin >> S, S != "#";){
        int len = S.size();

        int h = 0, w = 0;
        vector<vector<int>> field(1);

        for(auto& c : S){
            if(c == '/'){
                field.push_back(vector<int>());
                h++;
            }
            else if('1' <= c and c <= '9'){
                int num = c - '0';
                rep(loop, num){
                    field[h].push_back(0);
                }
            }
            else {
                field[h].push_back(1);
            }
        }
        h++;
        w = field[0].size();

        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--, d--;
        field[c][d] = field[a][b];
        field[a][b] = 0;

        string res = "";
        rep(y, h){
            if(y != 0) res += '/';
            int cnt = 0;
            rep(x, w){
                int cur = field[y][x];
                if(cur == 0){
                    cnt++;
                }
                else {
                    if(cnt > 0){
                        res += (cnt + '0');
                        cnt = 0;
                    }
                    res += 'b';
                }
            }
            if(cnt > 0){
                res += (cnt + '0');
                cnt = 0;
            }
        }

        cout << res << endl;
    }

    return 0;
}