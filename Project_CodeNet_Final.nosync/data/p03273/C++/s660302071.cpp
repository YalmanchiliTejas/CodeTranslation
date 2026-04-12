#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef long long ll;
typedef long long integer;
//////////////////////////////////////////////////
 /* AtCoder Beginner Contest 107 (๑•﹏•๑｀) */

int main(){
    int H,W; SCD2(H,W);
    static char grid[102][102] = {};

    FORq(i,1,H){
        FORq(j,1,W){
            cin >> grid[i][j];
        }
        getchar();
    }

    set<int> yoko;
    set<int> tate;

    FORq(i,1,H){
        bool flg = true;
        FORq(j,1,W){
            if (grid[i][j] == '#') flg = false;
        }
        if (flg) yoko.insert(i);
    }

    FORq(j,1,W){
        bool flg = true;
        FORq(i,1,H){
            if (grid[i][j] == '#') flg = false;
        }
        if (flg) tate.insert(j);
    }

    FORq(i,1,H){
        bool iflg = true;
        FORq(j,1,W){
            if (SIN(i,yoko)){
                iflg = false;
                break;
            }
            if (SIN(j,tate)) continue;
            cout << grid[i][j];
        }
        if (iflg) cout << "\n";
    }
    cout << "\n";
}