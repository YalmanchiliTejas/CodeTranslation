#include<bits/stdc++.h>
using namespace std;

#define ll long long

int mod(string num, int a) {
    int res = 0;
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;
    return res;
}

string k;
ll d;
ll n;

ll M = 1e9+7;

ll dp[10002][2][102];

ll f(ll cur, bool b, ll sum){
    if(cur==n){
        if(sum%d==0) return 1;
        else return 0;
    }

    if(dp[cur+1][b][sum]!=-1) return dp[cur+1][b][sum]%M;

    if(b){
        ll ans=0;
        for(ll i=0;i<=9;i++){
            ans+=(f(cur+1, b, (sum+i)%d))%M;
            ans%=M;
        }
        ans%=M;
        return dp[cur+1][b][sum] = ans%M; // dp[cur][b][sum] =
    }

    else{
        ll z = k[cur]-'0';
        ll ans=0;
        for(ll i=0;i<z;i++){
            ans+=(f(cur+1, true, (sum+i)%d))%M;
            ans%=M;
        }
        ans%=M;
        ans+=(f(cur+1, false, (sum+z)%d))%M;
        ans%=M;
        return dp[cur+1][b][sum] = ans%M; //
    }
}

int main(){
    // cout<<(-1+M)%M;
    memset(dp, -1, sizeof(dp));
    cin>>k>>d;
    n=k.length();
    cout<<(f(0, false, 0) - 1 + M) % M<<endl;
    return 0;
}