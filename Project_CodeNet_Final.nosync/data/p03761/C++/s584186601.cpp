#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string S[51];
    rep(i, n) cin >> S[i];
    string A;
    while(true) {
        bool exist = false;
        rep(i, 26) {
            bool exist1 = true;
            rep(j, n) {
                bool ok = false;
                rep(k, S[j].length()) {
                    if (S[j][k] == 'a' + i) ok = true;
                }
                if(!ok) exist1 = false;
            }
            if(exist1) {
                A += 'a' + i;
                rep(j, n) {
                    rep(k, S[j].length()) {
                        if (S[j][k] == 'a' + i) {
                            S[j].erase(k, 1); 
                            break;
                        }
                    }
                }
                exist = true;
                break;
            }
        }
        if(!exist) break;
    }
    cout << A << endl;


    return 0;
}
