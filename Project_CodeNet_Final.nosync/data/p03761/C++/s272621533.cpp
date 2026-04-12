#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;


int main() {

    int n; cin >> n;
    int tmp;
    string s;
    string ans = "";
    vector<vector<int>> v(n,vector<int>(26,0));

    rep(i,n){
        cin >> s;
        rep(j,s.size()){
            v[i][(int)(s[j]-'a')] ++;
        }
    }


    rep(i,26){
        tmp = 100000;
        rep(j,n){
            tmp = min(tmp,v[j][i]);
            if(tmp == 0) break;
            if(j == n-1){
                rep(k,tmp){
                    ans += char('a' + i);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
