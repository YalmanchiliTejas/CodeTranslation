#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={-1, 0, 1,0, 0};
int dx[]={0,1, 0, -1, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

ll n,m;
char c[200][200];

bool dfs(ll i ,ll j,ll d,ll gi,ll gj) {
    if(i == gi && j == gj) {
        return true;
    }

    for(int k = -1;k < 3;k++) {
        ll x = i + dx[(k + d + 4) % 4];
        ll y = j + dy[(k + d + 4) % 4];
        if(0 <= x && x < n && 0 <= y && y < m && c[x][y] == '.') {
            c[x][y] = '#';
            if(dfs(x,y,(k + d + 4) % 4,gi,gj)) 
                return true;
            //c[x][y] = '.';
        }
    }
    return false;
}
void out () {
    REP(i,n)
        cout << c[i] << endl;
    cout << "\n\n";
}

int main(){
    while(true) {
        cin >> n >> m;
        if(n == 0)
            break;
        REP(i,n) {
            REP(j,m) {
                cin >> c[i][j];
            }
        }
        bool f = dfs(0,0,1,n-1,0);
        //cout << f << endl;
        //out();
        f = (f && dfs(n-1,0,2,n-1,m-1));
        //cout << f << endl;
        //out();
        f = (f && dfs(n-1,m-1,3,0,m-1));
        //cout << f << endl;
        //out();
        f = (f && dfs(0,m-1,0,0,0));
        //cout << f << endl;
        //out();
        if(f)
            cout << "YES" << endl;
        else
            cout<< "NO" << endl;
    }
}


