#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ff first
#define ss second
typedef long long ll;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll dp[10002][100][2];
string s;
int n,d;
ll calc(int pos,int val,int f){
    if(pos==n)
        return (val==0);
    ll &ans=dp[pos][val][f];
    if(ans!=-1)
       return ans; 
    ans=0ll;
    int hi=(f==0)?(s[pos]-'0'):9;
    for(int i=0;i<=hi;i++){
        int _f=(f|(i<hi));
        ans+=calc(pos+1,(val+i)%d,_f);
    }
    ans%=MOD;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>s;
        cin>>d;
        n=s.length();
        cout<<((calc(0,0,0)-1+MOD)%MOD)<<"\n";
    }
    return 0;
}