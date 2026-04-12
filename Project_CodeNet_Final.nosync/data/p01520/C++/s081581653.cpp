#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int main(){
    int n,t,e;
    cin>>n>>t>>e;
    int x[200];
    rep(i,n){
        cin>>x[i];
    }
    int ans=-1;
    rep(i,n){
        int num=x[i];
        for(int j=1;;j++){
            if(num*j>=t-e && num*j<=t+e){
                ans=i+1;
                break;
            }
            if(num*j>t+e)break;
        }
    }
    cout<<ans<<endl;
}