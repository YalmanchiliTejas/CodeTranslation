#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;


int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    REP(i, h){
        REP(j, w){
            cin >> a[i][j];
        }
    }
    
    vector<int> s(h), t(w);
    REP(i, h){
        int x = 0; int y = 0;
        REP(j, w){
            if (a[i][j] == '.') x++;
            //else if(a[i][j] == '#') y++;
        }
        if(x == w || y == w) s[i] = 0;
        else s[i] = 1;
    }

    REP(i, w){
        int x = 0; int y = 0;
        REP(j, h){
            if (a[j][i] == '.') x++;
            //else if(a[j][i] == '#') y++;
        }
        if(x == h || y == h) t[i] = 0;
        else t[i] = 1;
    }

    int c = 0; int d = 0;
    REP(i, h){
        if(s[i] == 1) c++;
    }
    REP(i, w){
        if(t[i] == 1) d++;
    }

    if(c + d == 0){
        cout << "\n";
    }else {       
        REP(i, h){
            bool skip = false;
            REP(j, w){
                if(s[i] != 0 && t[j] != 0){
                    cout << a[i][j];
                }else if (s[i] == 0){
                    skip = true;
                }
            }

            if (skip){
                skip = false;
            }else {
                cout << "\n";
            }
        }
    }
    
}
