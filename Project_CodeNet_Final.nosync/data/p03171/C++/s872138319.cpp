#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*bool subseq(string s,string t){
    ll y=0;
    for(ll i=0;y<s.size()&& i<t.size();i++){
        if(s[y]==t[i]){
            y++;
        }
    }
        if(y==s.size())
            return true;
        else  return false;
}*/
/*ll x=1000000001;
vector<bool>p(x,false);
void prime(){
    p[2]=true;
    for(ll i=3;i<x;i=i+2)
        p[i]=true;
    for(ll i=0;i<x;i=i+2){
        if(p[i]){
            for(ll j=i*i;j<x;j=j+i)
                p[j]=false;
        }
    }
}*/
/*vector<ll> divisor(ll n){
    vector<ll> d;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
        d.push_back(i);
        d.push_back(n/i);
        }
    }
    sort(d.begin(),d.end(),greater<ll>());
    return d;
}*/
/*bool bs(ll n,string s){
    ll a[4]={0};
    for(ll i=0;i<n-1;i++){
        a[s[i]-'0']++;
    }
    for(ll i=n-1;i<s.size();i++){
        a[s[i]-'0']++;
        if(a[1]>0 && a[2]>0 && a[3]>0)
        return true;
        a[s[i-n+1]-'0']--;
    }
    return false;
}*/


/*ll binarySearch(ll n,ll a[],ll x){
    ll low=0,high=n-1,mid,ans=-1;
    while(low<=high){
        mid=low+(high-low)/2;
        if(a[mid]>=x){

            high=mid-1;
        }
        else{
                ans=mid;
            low=mid+1;
        }
    }
    return a[ans];
}*/
/*ll lcs(string a,string b,ll n,ll m){
    ll dp[n+1][m+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(i==0|| j==0)
                dp[i][j]=0;
            else if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];

}*/
/*ll editDist(string a,string b,ll n,ll m){
    vector<vector<ll> >dp(n+1,vector<ll>(m+1,-1));
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    return dp[n][m];
}*/

/*ll d1(vector<string>a,ll n,ll m,vector<vector<ll> >dp){
    if(n<0 || m<0 ) return 0;
    if(n==0 && m==0) return 0;
    if(a[n][m]=='#') dp[n][m]=0;
    if((n==0 &&m==1) || (m==0&&n==1)) return 1 ;
    if(dp[n][m]!=-1)
        return dp[n][m];

    dp[n][m]=d(a,n-1,m,dp)+d(a,n,m-1,dp);
    return dp[n][m];
}*/
/*ll solve(vector<ll>a,vector<ll>b,vector<ll>c,ll n,ll f,ll dp[][4]){
    if(n==0) return 0;
    if(dp[n][f]!=-1)
        return dp[n][f];
    if (f==1)
        return dp[n][1]=max(b[n-1]+solve(a,b,c,n-1,2,dp),c[n-1]+solve(a,b,c,n-1,3,dp));
    if(f==2)
        return dp[n][2]=max(a[n-1]+solve(a,b,c,n-1,1,dp),c[n-1]+solve(a,b,c,n-1,3,dp));
    if(f==3)
        return dp[n][3]=max(b[n-1]+solve(a,b,c,n-1,2,dp),a[n-1]+solve(a,b,c,n-1,1,dp));
    return max(a[n-1]+solve(a,b,c,n-1,1,dp),max(b[n-1]+solve(a,b,c,n-1,2,dp),c[n-1]+solve(a,b,c,n-1,3,dp)));
}*/
//ll y=0,x=0;
ll solve(ll n,vector<ll>a){
    ll dp[n][n];
    for(ll l=n-1;l>=0;l--){
        for(ll r=l;r<n;r++){
            if(l==r) dp[l][r]=a[l];
            else dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    return dp[0][n-1];
}

int main() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    cout<<solve(n,a);

}

