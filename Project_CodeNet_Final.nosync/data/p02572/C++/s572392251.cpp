/*
Created by Rishu Sahu @ covid 20-20
*/
/*
*****************************************************************
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pai pair<int,int>
#define pal pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,a,b) for(int i=a;i<=b;i++)
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define vi vector<int>
#define vl vector<ll>
#define mpl map<ll,ll>
#define mpi map<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const int mod = 1e9+7;
const int INF = INT_MAX;
const int mxm = 500000;
mpl mp;

ll prime[mxm];
vi vec;

void seive(){
    rep(i,mxm) prime[i]=1;
    prime[1]=prime[0]=0;
    for(int i=2;i*i<mxm;i++){
        if(prime[i]){
            for(int j=i*i;j<mxm;j+=i) 
            prime[j]=0;
        }
    }
    for(int i=2;i<mxm;i++) {
        if(prime[i])
        vec.pb(i);
    }
}

void factor(ll x){
   for(int i=0;vec[i]*vec[i]<=x;i++){
       if(x%vec[i]==0){
           mp[vec[i]]++;
           if(vec[i]*vec[i]!=x)
           mp[x/vec[i]]++;
       }
   }
   mp[x]++;
}

void solve(){
    int n;
    cin>>n;
    ll arr[n];
    rep(i,n) cin>>arr[i];
    ll ans=0,sum=arr[n-1];
    for(int i=n-2;i>=0;i--){
        ans=ans+(arr[i]*sum)%mod;
        ans=ans%mod;
        sum=(sum+arr[i])%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}


int main(){
    int t=1;
    seive();
    //cin>>t;
    while(t--){
        //mp.clear();
        solve();
    }
}