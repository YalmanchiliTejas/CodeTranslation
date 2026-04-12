#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h){
        cin >> s[i];
    }
    vector<int> col(w, 1), row(h, 1);
    rep(i, h){
        bool ok = false;
        rep(j, w){
            if (s[i][j] == '#'){
                ok = true;
                break;
            }
        }
        if (!ok) row[i] = 0;
    }
    rep(i, w){
        bool ok = false;
        rep(j, h){
            if (s[j][i] == '#'){
                ok = true;
                break;
            }
        }
        if(!ok) col[i] = 0;
    }
    rep(i, h){
        if (row[i] != 1) continue;
        rep(j, w){
            if(col[j] != 1) continue;
            cout << s[i][j];
        }
        cout << endl;
    }
}