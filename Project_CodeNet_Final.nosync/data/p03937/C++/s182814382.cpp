#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){

    bool tile[10][10];
    char ch;
    int h,w;
    int x=0,y=0;
    bool possi = true;

    cin >> h >> w;

    FOR(i,0,h){
        FOR(j,0,w){
            cin >> ch;
            if(ch == '.')tile[i][j] = false;
            else tile[i][j] = true;
        }
    }

    tile[0][0] = false;

    FOR(i,0,h+w-1){
        if(tile[x][y+1] == true && y+1 < w){
            tile[x][y+1] = false;
            y++;
        }else if(tile[x+1][y] == true){
            tile[x+1][y] = false;
            x++;
        }
    }

    FOR(i,0,h){
        FOR(j,0,w){
            if(tile[i][j] == true)possi = false;
        }
    }

    if(possi == true)cout << "Possible";
    else cout << "Impossible";

    return 0;
}
