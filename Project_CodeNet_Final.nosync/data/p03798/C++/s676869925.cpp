#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int n;
string s;

vector<char> func(vector<char> t){
    for(int i = 1; i < n; i++){
        if (s[i] == 'o'){
            if (t[i-1] == 'S' && t[i] == 'S') t.push_back('S');
            else if (t[i-1] == 'S' && t[i] == 'W') t.push_back('W');
            else if (t[i-1] == 'W' && t[i] == 'S') t.push_back('W');
            else if (t[i-1] == 'W' && t[i] == 'W') t.push_back('S');
        }
        else {
            if (t[i-1] == 'S' && t[i] == 'S') t.push_back('W');
            else if (t[i-1] == 'S' && t[i] == 'W') t.push_back('S');
            else if (t[i-1] == 'W' && t[i] == 'S') t.push_back('S');
            else if (t[i-1] == 'W' && t[i] == 'W') t.push_back('W');
        }
    }
    if (t[n] == t[0]){
        if (s[0] == 'o' && t[0] == 'S' && t[n-1] == t[1]) return t;
        else if (s[0] == 'o' && t[0] == 'W' && t[n-1] != t[1]) return t;
        else if (s[0] == 'x' && t[0] == 'S' && t[n-1] != t[1]) return t;
        else if (s[0] == 'x' && t[0] == 'W' && t[n-1] == t[1]) return t;
        else return {};
    }
    else return {};
}



int main(){
    cin >> n;
    cin >> s;

    vector<vector<char>> vc;
    vc.push_back({'S','S'});
    vc.push_back({'S','W'});
    vc.push_back({'W','S'});
    vc.push_back({'W','W'});

    rep(i, 4) {
        vector<char> ret = func(vc[i]);
        if (ret.size() > 2){
            rep(j, n) cout << ret[j];
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
