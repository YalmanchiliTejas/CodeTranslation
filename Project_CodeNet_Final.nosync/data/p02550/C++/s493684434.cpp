//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
//using Graph = vector<vector<int>>;
typedef long long ll;
using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n,x,m; cin>>n>>x>>m;
    vector<vector<ll>>amari(m,vector<ll>(2,-1));
    amari[x][0]=x;
    amari[x][1]=0;
    ll ans=x;
    ll cnt=0;
    bool B=false;
    for(ll i=1;i<n;i++){
         x=x*x%m;
        if(amari[x][0]!=-1){
            ans+=x;
            ll len=i-amari[x][1];
            ll sum=ans-amari[x][0];
            ll remain=n-(i+1);
            //cout<<i<<endl;
            ll howmanytime=remain/len;
           
            i+=howmanytime*len;
            cnt=i;
            //cout<<ans<<endl;
            //cout<<len<<endl;
            //cout<<sum<<endl;
            //cout<<remain<<endl;
            
            //return 0;

            ans+=howmanytime*sum;
            B=true;
            break;
        }
        else{
            ans+=x;
            amari[x][0]=ans;
            amari[x][1]=i;
        }
    }
   if(B){ for(ll i=cnt+1;i<n;i++){
               x=x*x%m;
                    ans+=x;
    }
   }
    cout<<ans<<endl;
}









