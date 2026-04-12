#include<bits/stdc++.h>
using namespace std;
string k;
int d;
long long mod = 1e9 + 7;
long long count(vector<vector<vector<long long> > > &dp, int pos, int s, int t){
    if(pos==k.length()){
    //    cout<<"sss "<< s <<endl;
        if(s%d)
            return 0;
        return 1;
    }
   // s %= d;
    long long ans=0;

    if(dp[pos][s][t] != -1 )
        return dp[pos][s][t];
    int kk = k[pos]-'0';
    if(t){
        int temp = count(dp,pos+1, (s + kk)%d, t);
        ans += temp;
       // cout<<pos<<" "<<temp<<" e "<<ans<<endl;
    }
    else kk = 10;
    for(int a=0; a<kk; a++){
        long long temp = count(dp,pos+1,(s + a)%d, 0);
        ans += temp;
       // cout<<pos<<" "<<temp<<" "<<ans<<endl;
    }

        dp[pos][s][t] = ans%mod;
    return  ans%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k>>d;
    vector<vector<vector<long long> > > dp(k.length()+2,vector<vector<long long > > (d+12, vector<long long> (2, -1)));
    long long ans = 0;
    ans = count(dp,0,0,1);
    ans -= 1;
    ans = ((ans%mod) + mod)%mod;
    cout<<ans<<endl;
    return 0;
}
