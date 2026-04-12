#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int mod = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1.0);

int main()
{
    int h,w;
    cin >> h >> w;
    char a[h][w];
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
    queue<P> que;
    que.push(P(0,0)); a[0][0] = '.';
    int x[] = {1,0},y[] = {0,1};
    int cnt = 1;
    while(que.size()){
        P p = que.front();
        que.pop();
        for(int k = 0; k < 2; k++){
            int nx = p.first+x[k],ny = p.second+y[k];
            if(0 <= nx && nx < w && 0 <= ny && ny < h && a[ny][nx] == '#'){
                a[ny][nx] = '.';
                que.push(P(nx,ny));
                cnt++;
            }
        }
    }
    int flag = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            //cout << a[i][j];
            if(a[i][j] == '#') flag = 1;
        }
        //cout << endl;
    }
    cout << (flag || cnt != w+h-1 ? "Impossible" : "Possible") << endl;
    return 0;
}