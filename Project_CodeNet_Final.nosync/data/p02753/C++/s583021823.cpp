#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    string s;
    cin >> s;
    bool a = false, b = false;
    rep(i, 3) {
        if (s[i] == 'A') a = true;
        else
            b = true;
    }
    if(a&&b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}