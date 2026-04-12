#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define forn(i,a,b) for (int i = a; i <= b; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define pi pair <int, int>
#define sz(x) (int)((x).size())
#define make_unique(v) v.erase(unique(all(v)),v.end())
#define int long long

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const ll inf = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 200 + 11;

int n,m,D,dp[N][2],dp1[N][2];

string K;

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);

    cin >> K >> D;

    dp[0][0] = 1;

    for(int i = sz(K) - 1; i >= 0; i--){
        int x = K[i] - '0';

        //dp[rest][0] - all the good posibilities by now
        //dp[rest][1] - all the bad posibilities by now
       

        for(int sum = 0; sum < D; sum++){
            for(int dig = 0; dig <= 9; dig++){
                if(x == dig){
                    dp1[(sum + dig)%D][0] += (dp[sum][0])%mod;
                    dp1[(sum + dig)%D][0] %= mod;

                    dp1[(sum + dig)%D][1] += (dp[sum][1])%mod;
                    dp1[(sum + dig)%D][1] %= mod;
                }else{
                    dp1[(sum + dig)%D][(dig > x ? 1 : 0)] += (dp[sum][1] + dp[sum][0])%mod;
                    dp1[(sum + dig)%D][(dig > x ? 1 : 0)] %= mod;
                }
            }
        }

        for(int k = 0; k < D; k++){
            for(int b = 0; b <= 1; b++){
                dp[k][b] = dp1[k][b];
                dp1[k][b] = 0;
            }
        }
    }

    int ans = dp[0][0] - 1;
    ans %= mod;
    ans += mod;
    ans %= mod;
    rc(ans);
return 0;
}