#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q;

int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n;
      ll x,pre=0,ans=0;
      for(int i=0;i<n;i++){
        cin>>x;
        ans=(ans + (x*pre)%M)%M;
        pre=(pre+x)%M;
      }
      cout<<ans;
}