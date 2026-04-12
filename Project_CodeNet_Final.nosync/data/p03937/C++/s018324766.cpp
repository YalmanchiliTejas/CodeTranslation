#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;
vector<int> dx = {1,0};
vector<int> dy = {0,1};

int h,w;
int pass = 0;
void dfs(vector<string> s, int nx, int ny) {
    if(nx > w -1 || ny > h -1) return;
    if(s.at(ny).at(nx) == '.') return;
    
    s.at(ny).at(nx) = '/';
    bool flag = 1;
    if(nx == w - 1 && ny == h-1) {
        rep(i,h){
            rep(j,w){
               if(s.at(i).at(j) == '#') {
                    flag = 0;
                    return;
              }
            } 
        }
        pass++;
        return;
    }
    
    rep(i,2) {
            dfs(s, nx+dx.at(i), ny+dy.at(i));
    }
    s.at(ny).at(nx) = '/';
    return;
}

int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);
    dfs(s,0,0);
    if(!pass) cout << "Impossible" << endl;
    else cout << "Possible" << endl;
}