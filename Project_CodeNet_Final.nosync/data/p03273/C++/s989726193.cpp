#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>
#include <map>
#include <set>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define INF 1145141919
typedef long long int ll;
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    char board[h][w];
    REP(i,h) REP(j,w) cin >> board[i][j];

    int hold=0,mincount=1000000,mincount2=1000000;

    REP(i,h){
        int count=0;
        REP(j,w){
            if(board[i][j]=='.'){
                count++;
            }
        }
        if(count<mincount)  mincount=count;
        if(count==w){
            REP(j,w){
                board[i][j]='A';
            }
            hold++;
        }
    }

    cout << endl;

    REP(j,w){
        int count=0;
        REP(i,h){
            if(board[i][j]=='.'){
                count++;
            }
        }
        if(count<mincount2) mincount2=count;
        if(count==h-hold){
            REP(i,h){
                board[i][j]='A';
            }
        }
    }

    REP(i,h){
        int count2=0;
        REP(j,w){
            if(board[i][j]!='A'){
                cout << board[i][j];
                count2++;
            }
        }
        //cout << count2 << endl;
        cout << endl;
    }
    return 0;
}