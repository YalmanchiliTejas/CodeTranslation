#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

#define ns first
#define ew second

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

const int N = 4;

string rank = "23456789TJQKA";

int main(void){
    for(char tarSuit; cin >> tarSuit, tarSuit != '#';){
        pii res = mp(0, 0);
        int winner = 0;

        vector<vs> in(13, vs(N));
        rep(i, N){
            rep(j, 13){
                cin >> in[j][i];
            }
        }

        rep(i, 13){
            int maxr = 0;

            vs cards = in[i];
            char tableSuit = cards[winner].at(1);

            rep(j, N){
                string card = cards[j];

                char suit = card.at(1);
                int r = rank.find(card.at(0));

                if(suit == tarSuit) r += 26;
                else if(suit == tableSuit) r += 13;

                if(maxr < r){
                    maxr = r;
                    winner = j;
                }
            }

            if(winner % 2 == 0) res.ns++;
            else res.ew++;
        }

        if(res.ns < res.ew) cout << "EW " << res.ew - 6 << endl;
        else                cout << "NS " << res.ns - 6 << endl;
    }

	return 0;
}