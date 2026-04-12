#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int a[100][100];

int main(){
    int N, M;
    cin >> N >> M;
    REP(i, N) REP(j, N) cin >> a[i][j];
    REP(i, M){
        int ope;
        cin >> ope;
        if(ope == 0){
            int y, x, l, arg;
            cin >> y >> x >> l >> arg;
            x--; y--;
            assert(x + l <= N && y + l <= N);
            arg /= 90;
            while(arg--){
                int tmp[100][100];
                REP(i, N) REP(j, N) tmp[i][j] = a[i][j];
                REP(dy, l) REP(dx, l) {
                    a[y + dy][x + dx] = tmp[y + l - 1 - dx][x + dy];
                }
            }
        }else if(ope == 1){
            int y, x, l;
            cin >> y >> x >> l;
            x--; y--;
            assert(x + l <= N && y + l <= N);
            REP(dy, l) REP(dx, l) a[y + dy][x + dx] ^= 1;
        }else if(ope == 2){
            int y;
            cin >> y;
            y--;
            int tmp[100];
            REP(x, N) tmp[x] = a[y][x];
            REP(x, N) a[y][x] = tmp[(x + 1) % N];
        }else if(ope == 3){
            int y;
            cin >> y;
            y--;
            int tmp[100];
            REP(x, N) tmp[x] = a[y][x];
            REP(x, N) a[y][x] = tmp[(x + N - 1) % N];
        }else if(ope == 4){
            int y, x;
            cin >> y >> x;
            x--; y--;
            bool b[100][100] = {};
            b[y][x] = true;
            int dx[4] = {1, 0, -1, 0};
            int dy[4] = {0, 1, 0, -1};
            bool update = true;
            while(update){
                update = false;
                REP(i, N) REP(j, N) if(b[i][j])
                REP(r, 4) if(0 <= i + dy[r] && i + dy[r] < N && 0 <= j + dx[r] && j + dx[r] < N && a[i][j] == a[i + dy[r]][j + dx[r]]){
                    if(!b[i + dy[r]][j + dx[r]]){
                        update = true;
                        b[i + dy[r]][j + dx[r]] = true;
                    }
                }
            }
            REP(i, N) REP(j, N) if(b[i][j]) a[i][j] ^= 1;
        }
    }
        REP(y, N) {
            REP(x, N){
                cout << a[y][x];
                if(x == N - 1) cout << endl;
                else cout << " ";
            }
        }
    return 0;
}