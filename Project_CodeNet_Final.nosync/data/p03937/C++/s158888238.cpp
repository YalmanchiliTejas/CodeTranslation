#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

vector<vector<int>> ed(8,vector<int>(8));

int dfs(int y, int x,vector<string> a,int h,int w)
{
    if(a[y][x]=='#'){
        ed[y][x] = 1;
    }else{
        return 0;
    }

    //右と下を見る,行ったことがあるなら見ない
    if (y < h - 1 && ed[y + 1][x] == 0 && a[y+1][x] == '#')
    {
        dfs(y + 1,x,a,h,w);
        return 0;
    }

    if (x < w - 1 && ed[y][x + 1] == 0 && a[y ][x+1] == '#')
    {
        dfs(y , x+1,a,h,w);
        return 0;
    }

    return 0;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h) { cin >> a[i];}
    int ans;

    dfs(0,0, a, h, w);

    REP(i,h){
        REP(j,w){
        int n = ed[i][j];
        if(n==0&&a[i][j]=='#'){
            cout << "Impossible"
                 << "\n";
            return 0;
        }
        //cout << n ;
    }
    //cout << "\n";
    }

    cout << "Possible"
         << "\n";
    //cout << ans <<"\n";

    return 0;
}