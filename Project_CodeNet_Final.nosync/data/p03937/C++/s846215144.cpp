#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;

int h, w;
vector<string> a;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool ans = true;

void dfs(int x = 0, int y = 0, int xx = -1, int yy = -1){
    if(x == h - 1 && y == w - 1){
        if(a[x][y] == '#') {
            if(ans) ans = true;
        }
    }
        rep3(i, 2, 3){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx == xx && ny == yy) continue;
            if(nx < 0 || nx >= h) continue;
            if(ny < 0 || ny >= w) continue;
            if(a[nx][ny] == '#') {
                ans = false; 
                return;
            }
        }
        
        int flag = 0;
        rep3(i, 0, 1){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= h || ny >= w) flag++;
            else if(a[nx][ny] == '.') {
                flag++;
            }else{
                flag = 0;
                // cout << "dfs: " << nx << " " << ny << " "  << x << " " << y << endl;
                dfs(nx, ny, x, y);
            }
        }
        if(flag == 2 && !(x == h-1 && y == w-1)) {
            ans = false; 
            return;
        }
}

void Main(){
    cin >> h >> w;
    a.resize(h); 
    rep(i, h) cin >> a[i];
    
    dfs();
    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl; 
    
    return;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}