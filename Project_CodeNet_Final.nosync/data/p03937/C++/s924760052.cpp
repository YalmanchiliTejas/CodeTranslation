#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))


bool solve(int H, int W, vector<string>& a){
    int te = (H-1) + (W-1);
    vector<int> pat(te, 1);
    rep(i, H-1) pat[i] = 0;
    char board[8][8];
    do{
        mset(board, '.');
        int x=0,y=0;
        board[y][x] = '#';
        rep(i,te){
            if (pat[i] == 1) ++x;
            else ++y;
            board[y][x] = '#';
        }
#ifdef DEBUG
        cout << pat << endl;
        rep(y,H){
            rep(x,W) putchar(board[y][x]);
            putchar('\n');
        }
        cout << '-' << endl;
        rep(y,H){
            cout << a[y] << endl;
        }
#endif
        bool ok = true;
        rep(y,H)rep(x,W){
            if (board[y][x] != a[y][x]){
                ok = false; goto bad;
            }
        }
        return true;
    bad:
        ;

    } while(next_permutation(ALL(pat)));

    return false;
}

int main() {
    int H,W;
    cin >> H>>W;
    vector<string> a(H);
    rep(i,H) cin >> a[i];
    cout << (solve(H,W,a) ? "Possible":"Impossible") << endl;
    return 0;
}
