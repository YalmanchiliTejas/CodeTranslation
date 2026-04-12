#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
const int MOD = 1e9+7;
//struct area

//function area

//main area
int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    ll sum_2 = 0;
    rep(i,n){
        ll k;
        cin >> k;
        sum += k;
        sum_2 += ((k*k)%MOD);
        sum %= MOD;
        sum_2 %= MOD;
    }
    ll k = (sum*sum % MOD);
    cout << ((k - sum_2 + MOD)%MOD * 500000004)%MOD << endl;
}
/*



*/