#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

int n;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (true) {
        cin >> n;
        if (n == 0) break;
        int cntw = 0;
        int cntb = 0;
        int pre = -1;
        vector<int> wr, br;
        rep(i, n) {
            int c;
            cin >> c;
            int wsize = wr.size();
            int bsize = br.size();
            if (i % 2 == 0) {
                if (pre != c) {
                    if (c == 1) wr.pb(i - 1);
                    else br.pb(i - 1);
                    pre = c;
                }
                if (c == 0) cntw++;
                else cntb++;
            }
            else {
                if (c == 0) {
                    if (pre != c) {
                        cntw += i - wr[wsize - 1];
                        cntb -= i - wr[wsize - 1] - 1;
                        pre = c;
                        if (wr[wsize - 1] == -1) br.pb(-1);
                        wr.pop_back();
                    }
                    else cntw++;
                }
                else {
                    if (pre != c) {
                        cntb += i - br[bsize - 1];
                        cntw -= i - br[bsize - 1] - 1;
                        pre = c;
                        if (br[bsize - 1] == -1) wr.pb(-1);
                        br.pop_back();
                    }
                    else cntb++;
                }
            }
        }
        cout << cntw << endl;
    }
}