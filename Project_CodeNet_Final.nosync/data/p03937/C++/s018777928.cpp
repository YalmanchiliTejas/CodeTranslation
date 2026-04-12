#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define get0(x)     (get<0>(x))
#define get1(x)     (get<1>(x))
#define get2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       9223372036854775807LL
#define LLMIN       -9223372036854775808LL
#define IMAX        2147483647
#define IMIN        -2147483648
typedef long long LL;
using namespace std;

int main(void){
    int H,W;
    vector<string> vs;
    cin>>H>>W;
    REP(i,H){string s;cin>>s;vs.pb(s);}
    int y=0,x=0;
    while(1){
        vs[y][x]='.';
        if(y+1<H&&vs[y+1][x]=='#')
            y++;
        else if(x+1<W&&vs[y][x+1]=='#')
            x++;
        else
            break;
    }
    // REP(i,H)
        // cout<<vs[i]<<endl;
    int c=0;
    REP(i,H)REP(j,W)c+=(vs[i][j]=='#');
    if(c==0&&y==H-1&&x==W-1)
        cout<<"Possible"<<endl;
    else
        cout<<"Impossible"<<endl;
     return 0;
}