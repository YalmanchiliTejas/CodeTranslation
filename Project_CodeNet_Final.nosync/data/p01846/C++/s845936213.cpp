#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;
#define PI acos(-1.0)
#define EPS 1e-10
const ll INT = 1e16;
const ll MOD = 1e9 + 7;
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define rep(i,N) FOR(i, 0, N)
#define ALL(s) (s).begin(), (s).end()
#define EQ(a, b) (abs((a) - (b)) < EPS)
#define EQV(a, b) (EQ((a).reeal(), (b).real) && EQ((a).imag(), (b).imag()))
#define NIL -1

ll h,w;
ll a,b,c,d;
string s;
vector<string> vs;
bool field[10][10];

vector<string> split(string str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, sep)) {
        v.push_back(buffer);
    }
    return v;
}

ll fill(){
    ll width = 0;
    rep(i,h){
        int now = 0;
        rep(j,vs[i].size()){
            if(vs[i][j] == 'b'){
                field[i][now] = 1;
                now++;
            }
            else now += (vs[i][j] - '0');
        }
        width = now;
    }
    return width;
}

vector<string> solve(){
    vector<string> res;
    rep(i,h){
        string s = "";
        int cnt = 0;
        rep(j,w){
            if(field[i][j] == 0)cnt++;
            else{
                if(cnt != 0)s += (char)('0' + cnt);
                s += "b";
                cnt = 0;
            }
        }
        if(cnt != 0)s += (char)('0' + cnt);
        res.push_back(s);
    }
    return res;
}

int main(){
    while(cin >> s && s != "#"){
        rep(i,10)rep(j,10)field[i][j] = 0;
        vs.clear();
        vs = split(s,'/');
        h = vs.size();
        w = fill();
        cin >> a >> b >> c >> d;
        a--; b--;
        c--; d--;
        field[a][b] = 0;
        field[c][d] = 1;
        vector<string> ans = solve();
        rep(i,h){
            if(i != 0)cout << "/";
            cout << ans[i];
        }
        cout << endl;
    }
    
}
