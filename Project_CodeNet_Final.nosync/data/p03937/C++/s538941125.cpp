#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

int main(void){
    #ifdef ccsnoopy
        freopen("D:/Code/in.txt","r",stdin);
    #endif

    int h,w;
    sc(h);sc(w);
    char str[10][10];
    FOR(i,h)scanf("%s", str[i]);
    int ct = 0;

    FOR(i,h){
        FOR(j,w){
            if(str[i][j] == '#')ct++;
        }
    }
    ii xy = ii(0,0);
    int dr[] = {1,0};
    int dc[] = {0,1};
    while(true){
        ct--;
        int x = xy.first;
        int y = xy.second;
        bool found = false;
        FOR(i,2){
            int xb = x+dr[i];
            int yb = y+dc[i];
            if(xb >= 0 && xb < h && yb >= 0 && yb < w && str[xb][yb] == '#'){
                xy = ii(xb,yb);
                found = true;
                break;
            }
        }

        if(!found)break;

    }

    //printf("%d\n", ct);

    printf("%s", ct ? "Impossible":"Possible");





    return 0;
}



