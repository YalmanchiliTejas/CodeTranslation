#include<bits/stdc++.h>
using namespace std;

#define ll long long int

string str;
ll len;
ll dp[110][10][4][2];
ll cholo(ll id,ll last,ll ct,bool mark)
{
    if(id>=len){
        if(ct) return 0ll;
        else return 1ll;
    }
    ll &ret=dp[id][last][ct][mark];
    if(~ret) return ret;

    ll big=(mark) ? str[id]-'0' : 9;

    if(ct==0) big=0;

    ll sum=0;
    for(ll i=0;i<=big;i++){
        if(i==big) {
            if(i>0ll) sum+=cholo(id+1,i,ct-1,mark);
            else sum+=cholo(id+1,i,ct,mark);
        }
        else{
            if(i>0ll) sum+=cholo(id+1,i,ct-1,false);
            else sum+=cholo(id+1,i,ct,false);
        }
    }
    return (ret= sum);

}

int main()
{
    ll x,p,i,j,k;
    cin>>str>>k;
    len=str.length();
    memset(dp,-1,sizeof dp);
    ll ans=cholo(0,0,k,true);
    cout<<ans<<'\n';
}

