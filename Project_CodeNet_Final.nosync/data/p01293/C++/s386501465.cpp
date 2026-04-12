#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr,__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const char trump_chars[] = {'S', 'H', 'D', 'C'};

int main() {
    char trump;
    while (cin >> trump, trump != '#') {
        int tr = find(trump_chars, trump_chars+4, trump) - trump_chars;
        // num, (??????????????????2, ?????????????????????1, ??????0), trump, player
        vector<vector<tuple<int, int, int, int>>> cards(13, vector<tuple<int, int, int, int>>(4));
        vi score(4);
        REP(j, 4) {
            REP(i, 13) {
                char c, card;
                cin >> c >> card;
                int num = 0;
                switch (c) {
                case 'T':
                    num = 10;
                    break;
                case 'J':
                    num = 11;
                    break;
                case 'Q':
                    num = 12;
                    break;
                case 'K':
                    num = 13;
                    break;
                case 'A':
                    num = 14;
                    break;
                default:
                    num = c - '0';
                }
                int tt = find(trump_chars, trump_chars+4, card) - trump_chars;
                cards[i][j] = make_tuple(tt == tr ? 2 : 0, num, tt, j);
            }
        }

        int p = 0;
        REP(turn, 13) {
            int m = get<2>(cards[turn][p]);
            REP(i, 4) {
                if (get<2>(cards[turn][i]) == m) {
                    get<0>(cards[turn][i]) = 1;
                }
            }
            RSORT(cards[turn]);
//            LOG("%d %d %d %d\n", get<0>(cards[turn][0]), get<1>(cards[turn][0]), get<2>(cards[turn][0]), get<3>(cards[turn][0]));
            score[get<3>(cards[turn][0])]++;
            p = get<3>(cards[turn][0]);
        }
        if (score[0] + score[2] > score[1] + score[3]) {
            cout << "NS ";
            cout << (score[0] + score[2]) % 6 << endl;
        } else {
            cout << "EW ";
            cout << (score[1] + score[3]) % 6 << endl;
        }
    }
}