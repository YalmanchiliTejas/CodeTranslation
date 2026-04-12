#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(ll int i=a;i<=b;++i)
#define rep(i,n) for(ll int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=998244353;
#define N 3000000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
int n;
ll int a[51];

bool check(ll int m){
    ll int b=n-1-m;
    ll int res=0;
    rep(i,n){
        res+=max((ll)0,(a[i]-b+n)/(n+1));
    }
    return (res<=m);
}
main(){
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    ll int sum=0;
    rep(i,n){
        sum+=a[i]-n+1;
    }
  	sum=max(sum,(ll)0);
    rep2(i,sum,sum+n*n){
        if(check(i)){
            cout<<i; return 0;
        }
    }
}