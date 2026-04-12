#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve(){
    int h, w; 
    cin >> h >> w;
    vector<string> vs;
    REP(i, h){
        string s;
        cin >> s;
        vs.pb(s);
    }
    REP(i, h){
        bool flag = true;
        REP(j, w){
            if(vs[i][j] == '#') flag = false;
        }
        if(flag){
            REP(j, w) vs[i][j] = 'x';
        }
    }
    REP(i, w){
        bool flag = true;
        REP(j, h){
            if(vs[j][i] == '#') flag = false;
        }
        if(flag){
            REP(j, h) vs[j][i] = 'x';
        }
    }

    REP(i, h){
        string res;
        REP(j, w){
           
            if(vs[i][j] == 'x'){
                continue;
            }
            else{
                res += vs[i][j];
            } 
        }
        if(!res.empty()) cout << res << endl;
        else continue;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}