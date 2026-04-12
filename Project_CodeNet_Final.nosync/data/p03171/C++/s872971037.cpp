#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define vi vector
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define mod 998244353
#define pb push_back
#define ll long long int
#define db double
#define all(v) v.begin(),v.end()

using namespace std;

/*

ll expo(ll n){
    ll t;
    if(n==0)return 1;
    else if(n==1) return 2;
    t=expo(n/2);
    if(n%2){
        return t*t*2;
    }
    else return t*t;
}

//ffrom geek for geek
ll exponentMod(ll A, ll B, ll C)  
{  
    if (A == 0)  
        return 0;  
    if (B == 0)  
        return 1;  
    ll y;  
    if (B % 2 == 0) {  
        y = exponentMod(A, B / 2, C);  
        y = (y * y) % C;  
    }  
    else {  
        y = A % C;  
        y = (y * exponentMod(A, B - 1, C) % C) % C;  
    }  
  
    return (ll)((y + C) % C);  
}

*/
/*
class dsu{
public:    
vi<ll> v;


void init(ll n){
    v.assign(n+1,-1);
}

 
ll dsufind(ll x){
    if(v[x]<0){
        return x;
    }
    v[x]=dsufind(v[x]);
    return v[x];
}
 
void dsujoin(ll x,ll y){
    x=dsufind(x);
    y=dsufind(y);
    
    if(x==y)
    return;
    if(v[x]>v[y])swap(x,y);
    v[y]+=v[x];
    v[x]=y;
}

};
*/

ll a[3005];
ll dp[3001][3001];

ll go(ll l,ll r){
    if(l>r)
    return 0;
    if(r==l)
    return a[l];
    if(dp[l][r]!=-1)
    return dp[l][r];
    ll ans=a[l]-go(l+1,r);
    ans=max(ans,a[r]-go(l,r-1));
    dp[l][r]=ans;

    return ans;
}


int main(){
    IOS;
    ll t;
    t=1;
    ///cin>>t;
    while(t--){
        ll n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        FOR(i,n)cin>>a[i];
        cout<<go(0,n-1);
        
    }
    return 0;
} 
