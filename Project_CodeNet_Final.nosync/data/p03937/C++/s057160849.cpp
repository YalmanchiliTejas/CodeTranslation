#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

const int MAX_W = 8;
const int MAX_H = 8;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    string a[MAX_H];
    rep(i, h) cin >> a[i];
    int x = 0, y = 0;
    bool ans = true;
    h--; w--;
    a[0][0] = '*';
    
    while ((x != w) || (y != h)) {
        if (
            ((x > 0) && (a[y][x - 1] == '#')) ||
            ((y > 0) && (a[y - 1][x] == '#'))
        ) {
            ans = false;
            break;
        }
        
        if ((x < w) && (y < h) && (a[y][x + 1] == '#') && (a[y + 1][x] == '#')) {
            ans = false;
            break;
        }
        
        a[y][x] = '*';
        
        if ((x < w) && (a[y][x + 1] == '#')) {
            x++;
        }
        else if ((y < h) && (a[y + 1][x] == '#')) {
            y++;
        }
        else {
            ans = false;
            break;
        }
    }
    
    if (
        ((x > 0) && (a[y][x - 1] == '#')) ||
        ((y > 0) && (a[y - 1][x] == '#'))
    ) {
        ans = false;
    }
    
    cout << (ans ? "Possible" : "Impossible") << endl;
    return 0;
}
