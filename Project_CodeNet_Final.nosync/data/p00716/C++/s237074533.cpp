#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>

#define REP(i,n) for(i=0; i < (n); i++)
#define REPONE(i, n) for(i=1; i <= (n); i++)
#define LOOP(n) for(int loopCount=1; loopCount <= (n); loopCount++)
#define ITER(c) __typeof((c).begin())
#define EACH(c,it) for(ITER(c) it =(c).begin(); it!=(c).end(); it++)
#define SZ(c) ((int) (c).size())
#define ALL(c) c.begin(), c.end()
#define SUM(c) accumulate(ALL(c), 0)
#define EXIST(c,v) (find(ALL(c), (v)) != (c).end())
#define PB push_back
#define MP make_pair
#define fs first
#define sc second

using namespace std;
static const double EPS = 1e-9;
static const double PI = 3.141592653589793238462643383279;
typedef long long ll;

int main(){
    int rept;
    scanf("%d",&rept);
    LOOP(rept){
        int sub, money, year, i, j, n, pat, cnst, ans=0, cur;
        double multi;
        vector< pair<double, int> > fukuri, tanri;
        scanf("%d%d%d",&money,&year,&n);
        REP(i,n){
            scanf("%d%lf%d",&pat,&multi,&cnst);
            if(pat) fukuri.PB(MP(multi,cnst));
            else tanri.PB(MP(multi,cnst));
        }

        REP(i,SZ(fukuri)){
            cur = money;
            REP(j,year){
                cur += (int)(cur*fukuri[i].fs) - fukuri[i].sc;
            }
            ans = max(ans, cur);
        }
        REP(i,SZ(tanri)){
            cur = money;
            sub = 0;
            REP(j,year){
                sub += (int)(cur*tanri[i].fs);
                cur -= tanri[i].sc;
            }
            ans = max(ans, cur+sub);
        }

        printf("%d\n",ans);
    }

}