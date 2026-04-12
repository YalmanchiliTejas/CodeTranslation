#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll count(ll x,int n,vector<ll>th,vector<ll>pa){
    if(n==0)return 1;
    if(x==1)return 0;
    if(2<=x&&x<=th[n-1]+1)return count(x-1,n-1,th,pa);
    if(x==th[n-1]+2)return pa[n-1]+1;
    if(th[n-1]+3<=x&&x<=th[n]-1)return pa[n-1]+1+count(x-th[n-1]-2,n-1,th,pa);
    if(x==th[n])return pa[n];
}
int main(void){
    vector<ll>th(51),pa(51);
    th[0]=1;pa[0]=1;
    rep(i,50){
        th[i+1]=2*th[i]+3;
        pa[i+1]=2*pa[i]+1;
    }
    int n;ll k;cin>>n>>k;
    cout<<count(k,n,th,pa)<<endl;
}