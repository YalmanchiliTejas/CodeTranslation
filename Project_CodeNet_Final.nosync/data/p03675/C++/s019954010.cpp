#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;

int N;
ll a[200000];
int o[200000];

int main() {
    cin >> N;
    rep(i, N){cin >> a[i];}

    {
        int i = 0;
        int c = N-1;
        while(true){
            o[i] = c;
            c -= 2;
            i++;
            if(c < 0){
                c = -c -1;
                break;
            }
        }

        while(true){
            o[i] = c;
            c += 2;
            i++;
            if(c >= N){break; }
        }
    }

    /*
    rep(i, N){
        cerr << o[i] << ",";
    }
    cerr << endl;
    */

    rep(i, N){
        cout << a[o[i]];
        if(i < N-1) cout << " ";
    }
    cout << endl;
}