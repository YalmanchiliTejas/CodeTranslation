#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int dx[2] ={1,0};
const int dy[2] ={0,1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    queue<P> q;
    q.push({0,0});
    bool ok = false;
    vector<vector<bool>> che(h,vector<bool>(w,0));
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        che[x][y] = true;
        if(x==h-1 && y==w-1){
            ok = true;
            break;
        }
        bool one = false,two = false;
        rep(i,2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w || s[nx][ny]=='.') continue;
            q.push({nx,ny});
            if(i==0) one = true;
            if(i==1) two = true;
        }
        if(one && two){
            ok = false;
            break;
        }
    }
    rep(i,h) rep(j,w) if(s[i][j] == '#' && !che[i][j]) ok = false;
    cout << (ok? "Possible" : "Impossible") << endl;
}