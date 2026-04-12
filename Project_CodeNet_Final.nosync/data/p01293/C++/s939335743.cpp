#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;

int convRank(char r) {
    if (isdigit(r)) return r - '0';
    switch (r) {
        case 'T': return 10; break;
        case 'J': return 11; break;
        case 'Q': return 12; break;
        case 'K': return 13; break;
        case 'A': return 14; break; // <----!!!!!!!!
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    const int H = 4, W = 13;

    char trump;
    while (cin >> trump, trump != '#') {
        int  ranks[H][W];
        char suits[H][W];
        rep(i, H) {
            rep(j, W) {
                char r, s;
                cin >> r >> s;
                ranks[i][j] = convRank(r);
                suits[i][j] = s;
            }
        }

        int first = 0;
        V cnt_win(H, 0);
        rep(trick, W) {
            char s = suits[first][trick];
            int r = -1;
            int winner = first;
            rep(k, H) {
                int  np = (first + k) % H;
                int  nr = ranks[np][trick];
                char ns = suits[np][trick];
                if (s != trump && ns == trump) {
                    s = trump;
                    r = nr;
                    winner = np;
                } else if (ns == s && nr > r) {
                    r = nr;
                    winner = np;
                }
            }
            cnt_win[winner]++;
            first = winner;
        }

        int c1 = cnt_win[0] + cnt_win[2];
        int c2 = cnt_win[1] + cnt_win[3];
        cout << (c1 > c2 ? "NS" : "EW") << " " << max(c1 - 6, c2 - 6) << endl;

    }

}