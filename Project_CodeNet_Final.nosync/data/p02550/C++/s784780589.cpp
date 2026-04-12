#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN=1e5+1;

void solve(){
    int n,x,m,f=INT_MIN,curr;
    cin>>n>>x>>m;
    int pr=x;
    int ans=x;
    int res;
    map<int,int>mp;
    mp[x]=1;
    for(int i=2;i<=n;i++){
        res=(pr%m*pr%m)%m;
        if(mp[res]){
           int pr_pos=mp[res];
           int len=i-mp[res];
           int rem=n-(i-1);
           int c=rem/len;
           vector<int>cy,pre;
           for(int j=pr_pos;j<i;j++){
               int v=res;
               cy.push_back(v);
               res=(res*res)%m;
           }
           int pp=0;
           for(int j=0;j<cy.size();j++){
               pp+=cy[j];
               pre.push_back(pp);
           }
           ans+=c*pre[len-1];
           int rr=rem%len;
           if(rr){
               ans+=pre[rr-1];
           }
           break;
        }
        if(res==0){
            f=0;
            break;
        }
        if(res==1){
            f=1;
            curr=i;
            break;
        }
        ans+=res;
        pr=res;
        mp[res]=i;
    }
    if(f==1){
        ans+=n-curr+1;
        cout<<ans<<endl;
    }
    else
        cout<<ans<<endl;
}

signed main(){
    int t;
//    cin>>t;
//    while(t--){
        solve();
//    }
}