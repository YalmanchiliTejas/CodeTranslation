#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<int,int>
#define V vector<int>
#define M map<int,int>
#define S set<int>
#define PQ priority_queue<int>
#define PQG priority_queue<int,V,greater<int>>

#define pb(a) push_back(a)
#define mp make_pair

#define dump(x)  cout << #x << " = " << (x) << "\n";
#define COUT(x) cout<<(x)<<"\n"

int main()
{
    int h, w = 0;
    cin >> h >> w;
    vector<string> grid(h);

    REP(i, h)
    {
        cin >> grid[i];
    }

    vector<bool> row(h, false);
    vector<bool> col(w, false);

    REP (i, h)
    {
        REP(j, w)
        {
            if (grid[i][j] == '#')
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    REP(i, h)
    {
        if (row[i])
        {
            REP(j, w)
            {
                if (col[j])
                {
                    cout << grid[i][j];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}