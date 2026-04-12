#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<int> v_int;
typedef std::vector<v_int > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<v_ll > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<v_string > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<v_bool > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

const double PI = 3.14159265359;
const int INF = (int)1e9;
const ll LINF = 1e18;
const int IMOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

int main(void)
{
    int h, w;
    cin >> h >> w;

    char graph[h][w];

    irep(i, h) {
        irep(j, w) {
            cin >> graph[i][j];
        }
    }
    
    v2_bool seen(h, v_bool(w, false));

    queue<pii> q;
    q.push(pii(0,0));

    while(q.size()) {
        pii s = q.front(); q.pop();

        //printf("%d,%d\n", s.first, s.second);
        if(seen[s.first][s.second]) { continue; }
        
        seen[s.first][s.second] = true;
        
        bool left = false;
        irep(i, 4) {
            int row = s.first + dr[i];
            int col = s.second + dc[i];
            if(row < 0 || row >= h || col < 0 || col >= w) { continue; }
            if(seen[row][col] || graph[row][col] == '.') { continue; }
            if(i > 1) { left = true; }
            q.push(pii(row, col));
            //printf("%d,%d\n", row, col);
        }
        if(q.size() > 1 || left) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}
/** atcoder **/

