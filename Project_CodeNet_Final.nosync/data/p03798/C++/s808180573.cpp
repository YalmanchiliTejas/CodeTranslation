#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n; cin >> n;
    string s; cin >> s;
    string o[4] = {"WWS","SWW","SSS","WSW"};
    string x[4] = {"WSS","SSW","SWS","WWW"};
    char t[4][n+2];
    rep(i,4){
        rep(j,3){
            if(s[0]=='o') t[i][j] = o[i][j];
            else t[i][j] = x[i][j];
        }
        REP(j,1,n){
            if(s[j]=='o'){
                rep(k,4){
                    if(t[i][j]==o[k][0] && t[i][j+1]==o[k][1]){
                        t[i][j+2] = o[k][2];
                    }
                }
            }else{
                rep(k,4){
                    if(t[i][j]==x[k][0] && t[i][j+1]==x[k][1]){
                        t[i][j+2] = x[k][2];
                    }
                }
            }
        }
        if(t[i][0]==t[i][n] && t[i][1]==t[i][n+1]){
            REP(j,1,n+1){
                cout << t[i][j];
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
