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

ll N,M,H,W,K,A,B;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    cin>>S>>N;
    ll ls = S.size(),ns;
    ll N2=N;
    while(N2<10)  N2 *= 9;
    mat dp1(ls,vec(N2,0));//すでに下回ってる
    mat dp2(ls,vec(N2,0));//ギリギリ
    const int mod = (1e+9)+7;
    rep(i,ls){
        ns = S.at(i) - '0';
        if(i == 0){
            rep(j,ns) dp1.at(i).at(j) = 1;
            dp2.at(i).at(ns) = 1;
        }else {
            rep(j, N2) {
                rep(k, 10) {
                    if (j - k < 0) (dp1.at(i).at(j) += dp1.at(i-1).at(j - k + N2)) %= mod;
                    else (dp1.at(i).at(j) += dp1.at(i-1).at(j - k)) %= mod;
                }
                rep(k, ns) {
                    if (j - k < 0) (dp1.at(i).at(j) += dp2.at(i-1).at(j - k + N2)) %= mod;
                    else (dp1.at(i).at(j) += dp2.at(i-1).at(j - k)) %= mod;
                }
                if (j - ns < 0) (dp2.at(i).at(j) += dp2.at(i-1).at(j - ns + N2)) %= mod;
                else (dp2.at(i).at(j) += dp2.at(i-1).at(j - ns)) %= mod;
            }
        }
    }
    ll ans=0;
    if(N == N2) {
        (ans +=dp1.at(ls-1).at(0)+dp2.at(ls-1).at(0))%=mod;
        (ans += mod-1)%=mod;
        cout<<ans<<endl;
    }else{
        if(N != 1) rep(i,9) (ans += dp1.at(ls-1).at(N*i)+dp2.at(ls-1).at(N*i))%=mod;
        else rep(i,81)(ans += dp1.at(ls-1).at(N*i)+dp2.at(ls-1).at(N*i))%=mod;
        (ans += mod-1)%=mod;
        cout<<ans<<endl;
    }
    /*rep(i,ls){
        rep(j,N2){
            cout<<dp1[i][j]<<' ';
        }
        cout<<endl;
    }
    rep(i,ls){
        rep(j,N2){
            cout<<dp2[i][j]<<' ';
        }
        cout<<endl;
    }*/
}
