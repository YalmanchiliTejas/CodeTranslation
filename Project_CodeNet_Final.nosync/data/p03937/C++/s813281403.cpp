#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int h, w;
char a[10][10];
int d[10][10];

int bfs(){
    queue<P> que;
    rep(i, h){
        rep(j, w){
            d[i][j] = 100000;
        }
    }
    que.push(P(0, 0));
    d[0][0] = 0;

    while(que.size()){
        P p = que.front(); que.pop();

        if(p.first == h - 1 && p.second == w - 1)break;
        rep(i, 4){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if(0 <= nx && nx < h && 0 <= ny && ny < w && 
            a[nx][ny] != '.' && d[nx][ny] == 100000){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
                //cout << nx << " " << ny << endl;
            }
        }
    }
    return d[h - 1][w - 1];
}

int main(){
    cin >> h >> w;
    int count = 0;
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
            if(a[i][j] == '#')count++;
        }
    }
    int res = bfs();
    //cout << count << " " << res << endl;
    if(h + w - 1 == count)cout << "Possible" << endl;
    else cout << "Impossible" << endl;    
}