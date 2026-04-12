#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
#define fr first
#define sc second
#define mpr make_pair
#define pb push_back
#define ppb pop_back()
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define ins insert
const int mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 3e5 + 1, N2 = 5001, M = 51;
int n, m, cnt;
char a;
bool u[11][11];
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; ++ i){
        for(int j = 1;j <= m; ++ j){
            cin >> a;
            if(a == '#'){
                u[i][j] = 1;
                ++cnt;
            }
        }
    }
    if(cnt != n + m - 1){
        cout << "Impossible";
        return 0;
    }
    if(!u[1][1]){
        cout << "Impossible";
        return 0;
    }
    int x = 1, y = 1;
    for(int i = 1;i < cnt; ++ i){
        if(u[x + 1][y] ^ u[x][y + 1] == 0){
            cout << "Impossible";
            return 0;
        }
        if(u[x + 1][y])++x;
        else ++y;
    }
    cout << "Possible";
    return 0;
}
