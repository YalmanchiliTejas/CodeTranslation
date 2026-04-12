#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

int N,M,H,W,K,A,B;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a.at(i);
    mat dp(N,vec(N,0));//0-indexed;
    int t = (N&1)*2 - 1;
    rep(i,N) dp[i][i] = t*a[i];
    for(int i = N-1;i>=0;--i){
        t *= -1;
        int plus = N-i;
        rep(j,i){
            if(t == -1){
                dp.at(j).at(j+plus) = min(dp.at(j).at(j+plus-1)-a.at(j+plus),
                                        dp.at(j+1).at(j+plus)-a.at(j));
            }else{
                dp.at(j).at(j+plus) = max(dp.at(j).at(j+plus-1)+a.at(j+plus),
                                        dp.at(j+1).at(j+plus)+a.at(j));
            }
        }

    }
    /*rep(i,N){
        rep(j,N){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }*/
    cout<<dp[0][N-1]<<endl;
}