#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll dp[10010][101][2];

int main(){
    string s;
    cin >> s;
    int d;
    reverse(s.begin(),s.end());
    int n = s.size();
    cin >> d;
    ll ans = 0;
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        int th = s[i-1]-'0';
        for(ll j=0;j<10;j++){
            ll q = j;
            for(ll k=0;k<d;k++){
                ll md = (k+q)%d;
                if(j<th){
                    dp[i][md][0] += dp[i-1][k][0];
                    dp[i][md][0] += dp[i-1][k][1];
                    dp[i][md][0] %= mod;
                }else if(j==th){
                    dp[i][md][0] += dp[i-1][k][0];
                    dp[i][md][0] %= mod;
                    dp[i][md][1] += dp[i-1][k][1];

                    dp[i][md][1] %= mod;
                }else{
                    dp[i][md][1] += dp[i-1][k][0]; 
                    dp[i][md][1] += dp[i-1][k][1];

                    dp[i][md][1] %= mod;
                }
            }
        }
    }   
    ans = mod+dp[n][0][0]-1;
    ans %= mod;
    cout << ans << endl;
    return 0;
}