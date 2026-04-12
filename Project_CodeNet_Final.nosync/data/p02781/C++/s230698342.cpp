
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */



int main() {
    long long d;
    string n;
    cin >> n >> d;
    
    //dp[i][j][k] := 左からi桁目,　桁和がj(mod D), flag, の時の数え上げdp
    vector<vector<vector<long long> > > dp(n.size() + 1, vector<vector<long long> > (d + 1, vector<long long> (2, 0ll)));
    dp[0][0][0] = 1;
    for(int i = 0; i < n.size(); i++){
        for(int j = 0; j <= d; j++){
            
            //cout << "( ";
            for(int k = 0; k < 2; k++){
                //cout << dp[i][j][k] << " ";
 
                int num = (int)(n[i] - '0');
                for(int l = 0; l <= 9; l++){
                    int nj = j;
                    if(l != 0) nj++;
                    if(nj > d) continue;
                    if(k == 0 && l <= num){
                        dp[i + 1][nj][l != num] += dp[i][j][k];
                    }else if(k == 1){
                        dp[i + 1][nj][k] += dp[i][j][k];
                    }
                }
            }
 
            //cout << ") ";
        }
        //cout << endl;
    }
 
 
    //cout << endl;
    cout << (dp[n.size()][d][0] + dp[n.size()][d][1]) << endl;
 
    return 0;
  return 0;
}
