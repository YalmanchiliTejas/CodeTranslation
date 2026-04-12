#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

ll dp[200][2][4]={};

int main(void){
    ll k;
    string s;
    cin>>s>>k;
    dp[0][0][0]=1;
    ll n=s.size();
    for(int i=0;i<n;i++){
        ll x=s[i]-'0';
        for(int a=0;a<=9;a++){
            for(int z=0;z<=3;z++){
                if(a==0){
                    dp[i+1][1][z]+=dp[i][1][z];
                    if(a==x) dp[i+1][0][z]+=dp[i][0][z];
                    else if(a<x) dp[i+1][1][z]+=dp[i][0][z];
                }
                else if(z<3){
                    dp[i+1][1][z+1]+=dp[i][1][z];
                    if(a==x) dp[i+1][0][z+1]+=dp[i][0][z];
                    else if(a<x) dp[i+1][1][z+1]+=dp[i][0][z];
                }
            }
        }
    }
    cout<<dp[n][0][k]+dp[n][1][k]<<endl;
}