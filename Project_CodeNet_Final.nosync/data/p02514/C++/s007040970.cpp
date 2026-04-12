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

bool in(pair<int, int> l, pair<int, int> r, pair<int, int> p){
    return (l.fs<=p.fs && p.fs<=r.fs && l.sc<=p.sc && p.sc<=r.sc);
}

int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        int w, h, l1, l2;
        cin >> w >> h;
        map<string, vector<pair<pair<pair<int, int>, pair<int, int> >, string> > > dict;
        deque<string> qu;
        string cur;
        REP(l1,n){
            int mm;
            string line;
            cin >> line >> mm;
            if(l1==0) cur = line;
            REP(l2,mm){
                int x1, y1, x2, y2;
                string name;
                cin >> x1 >> y1 >> x2 >> y2 >> name;
                dict[line].PB(MP(MP(MP(x1,y1), MP(x2,y2)), name));
            }
        }
        qu.push_back(cur);
        int m, x, y, cp=0;
        string cmd;
        cin >> m;
        REP(l1,m){
            cin>>cmd;
            if(cmd=="click"){
                cin >> x >> y;
                REP(l2,SZ(dict[qu[cp]])){
                    if(in(dict[qu[cp]][l2].fs.fs, dict[qu[cp]][l2].fs.sc, MP(x,y))){
                        int rep=SZ(qu)-(cp+1);
                        LOOP(rep) qu.pop_back();
                        cp++;
                        qu.push_back(dict[qu[cp-1]][l2].sc);
                        break;
                    }
                }
            }
            else if(cmd=="show"){
                cout << qu[cp] << endl;
            }
            else if(cmd=="back"){
                if(cp>0) cp--;
            }
            else if(cmd=="forward"){
                if(cp<SZ(qu)-1) cp++;
            }
        }
    }
    return 0;
}