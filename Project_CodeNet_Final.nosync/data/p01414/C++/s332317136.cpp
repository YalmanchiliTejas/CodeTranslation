#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
int H[20], W[20];
string S[5];
int field[5][5];
int dist[1 << 17];
bool chmin(int &a, int b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int f(int nowbit, int stamp, int h, int w, int color) {
    int ans = nowbit;
    for(int dh = 0; dh < H[stamp]; dh++) {
        int newh = h + dh;
        if(newh < 0 || newh > 3) continue;
        for(int dw = 0; dw < W[stamp]; dw++) {
            int neww = w + dw;
            if(neww < 0 || neww > 3) continue;
            int grid = newh * 4 + neww;
            if(field[newh][neww] == color) ans |= (1 << grid);
            else ans &= ~(1 << grid);
        }
    }
    return ans;
}

int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> H[i] >> W[i];
    for(int h = 0; h <= 3; h++) cin >> S[h];
    for(int h = 0; h < 4; h++) {
        for(int w = 0; w < 4; w++) {
            if(S[h][w] == 'R') field[h][w] = 0;
            if(S[h][w] == 'G') field[h][w] = 1;
            if(S[h][w] == 'B') field[h][w] = 2;
        }
    }
    for(int i = 0; i < (1 << 16); i++) dist[i] = INF;
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()) {
        int nowbit = que.front();
        //cerr << nowbit << " " << dist[nowbit] << endl;
        //if(dist[nowbit] > 3) break;
        if(dist[(1 << 16) - 1] != INF) break;
        que.pop();
        for(int stamp = 0; stamp < N; stamp++) {
            for(int h = 1 - H[stamp]; h <= 3; h++) {
                for(int w = 1 - W[stamp]; w <= 3; w++) {
                    for(int color = 0; color <= 2; color++) {
                        int newbit = f(nowbit, stamp, h, w, color);
                        if(chmin(dist[newbit], dist[nowbit] + 1)) que.push(newbit);
                    }
                }
            }
        }
    }
    cout << dist[(1 << 16) - 1] << endl;
    return 0;
}

