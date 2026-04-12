#include <bits/stdc++.h>
#define ll long long int
#define forr(i,a,n) for(ll i=a;i<n;i++)
#define ford(i,a,n) for(ll i=n-1;i>=a;i--)
#define testc  ll ts;\
               cin>>ts;\
               while(ts--)
#define arn ll n;\
            cin>>n;\
            ll a[n];\
            forr(i,0,n)cin>>a[i];\
               
#define arr(a,n) ll a[n];\
                 forr(i,0,n)cin>>a[i];\
 
#define sss <<" "<<
#define nnn <<"\n"
#define nl cout<<"\n";
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    if(n>=30)cout<<"Yes";
    else cout<<"No";
    return 0;
}