#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main(){

    ll h,w;
    cin >> h >> w;
    char a[h][w];
    REP(i,h)
    {
        REP(j,w)
        {
            cin >> a[i][j];
        }
    }
    string res = "Possible";

    ll migi = 0;
    REP(i,h)
    {
        REP(j,w)
        {
            if(a[i][j] == '#')
            {
                if(i == 0)
                {
                    migi = j;
                }else
                {
                    if(j < migi)
                    {
                        res = "Impossible";
                    }
                    else
                    {
                        migi = j;
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;    
}

