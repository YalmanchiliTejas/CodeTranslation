#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353 
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
int n;
ll a[3000];
ll cost[3000][3000];
ll solve(ll i,ll j){
    if(cost[i][j]!=1e15)
        return cost[i][j];
    else{
        if((n-(j-i))%2==1)
            cost[i][j]=max(a[i]+solve(i+1,j),a[j]+solve(i,j-1));
        else
            cost[i][j]=min(solve(i+1,j)-a[i],solve(i,j-1)-a[j]);
        return cost[i][j];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        cin>>n;
        int ctr=1;
        if(n%2==0)
            ctr=-1;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(ll i=0;i<n;i++){
            cost[i][i]=ctr*a[i];
            for(ll j=i+1;j<n;j++)
                cost[i][j]=1e15;
        }
        cout<<solve(0ll,n-1)<<"\n";
    }
    return 0;
}