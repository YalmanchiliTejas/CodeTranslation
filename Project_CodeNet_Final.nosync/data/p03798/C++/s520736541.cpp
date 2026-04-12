#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
int main()
{
    int N;
    string S;
    cin >> N >> S;

    vector<vector<int>> check(4, vector<int>(N));
    check[0][0] = 0; check[0][N - 1] = 0;
    check[1][0] = 0; check[1][N - 1] = 1;
    check[2][0] = 1; check[2][N - 1] = 0;
    check[3][0] = 1; check[3][N - 1] = 1;

    vector<bool> flag(4, true);

    rep(i, N - 2) {
        rep(j, 4) {
            int be = (i == 0) ? N - 1 : i - 1;
            int af = i + 1;
            if (check[j][i] == 0) {
                if (S[i] == 'o') check[j][af] = check[j][be];
                else check[j][af] = (check[j][be] == 1) ? 0 : 1;
            }
            else {
                if (S[i] == 'x') check[j][af] = check[j][be];
                else check[j][af] = (check[j][be] == 1) ? 0 : 1;
            }
        }
    }

    rep(i, N) {
        rep(j, 4) {
            int be = (i == 0) ? N - 1 : i - 1;
            int af = (i == N - 1) ? 0 : i + 1;
            if (check[j][i] == 0) {
                if (S[i] == 'o') {
                    if (check[j][be] != check[j][af]) {
                        flag[j] = false;
                    }
                }
                else {
                    if (check[j][be] == check[j][af]) {
                        flag[j] = false;
                    }
                }
            }
            else {
                if (S[i] == 'o') {
                    if (check[j][be] == check[j][af]) {
                        flag[j] = false;
                    }
                }
                else {
                    if (check[j][be] != check[j][af]) {
                        flag[j] = false;
                    }
                }
            }
        }
    }

    int ans = -1;
    rep(i, 4) {
        if (flag[i]) {
            ans = i;
            break;
        }
    }
    
    if (ans == -1) cout << -1 << endl;
    else {
        rep(i, N) {
            cout << ((check[ans][i] == 0) ? 'S' : 'W');
        }
        cout << endl;
    }
    return 0;
}