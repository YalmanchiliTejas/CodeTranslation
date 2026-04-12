#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "-1" <<"\n"; return;}
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  1000000007
using namespace std;
using ll = long long;
using ld = long double;
using P  = pair<ll,ll>;
//--GLOBAL---------------------------------

//--MAIN-----------------------------------
void Main() {
    string S; cin>>S;
    ll N=S.size();
    ll K; cin>>K;
    ll dp[110][5][2]={}; // 桁 nokori ぴったり1 else0
    ll c0=S[0]-'0';
    dp[1][0][0]=1; //0
    dp[1][1][0]=c0-1; //それ以外
    dp[1][1][1]=1; //それ
    reps(i,1,N){
        ll c=S[i]-'0';
        rep(k,4){
            //今までぴったり
            // 0
            if(c==0) dp[i+1][k][1]+=dp[i][k][1];
            else dp[i+1][k][0]+=dp[i][k][1];
            // それ
            if(c!=0) dp[i+1][k+1][1]+=dp[i][k][1];
            //それ以外
            if(c!=0) dp[i+1][k+1][0]+=dp[i][k][1]*(c-1);

            //今までぴったりでない
            //0
            dp[i+1][k][0]+=dp[i][k][0];
            //0以外
            dp[i+1][k+1][0]+=dp[i][k][0]*9;
        }
    }
    cout<< dp[N][K][0]+dp[N][K][1] <<"\n";

}

//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------
