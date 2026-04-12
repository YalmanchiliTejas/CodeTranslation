#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int h, w;
    cin >> h >> w;
    string s[h];
    rep(i, h) cin >> s[i];
    int num1[h];
    int num2[w];
    rep(i, h) num1[i] = 0;
    rep(i, w) num2[i] = 0;

    rep(i, h){
        rep(j, w){
            if (s[i][j] == '#'){
                break;
            }
            if (j == w - 1 && s[i][j] == '.'){
                num1[i] = 1;
            }
        }
    }
    rep(i, w){
        rep(j, h){
            if (s[j][i] == '#'){
                break;
            }
            if (j == h - 1 && s[j][i] == '.'){
                num2[i] = 1;
            }
        }
    }
    rep(i, h){
        if (num1[i] == 0){
            rep(j, w){
                if (num2[j] == 0){
                    cout << s[i][j];
                }
            }
            cout << endl;
        }
    }
}
