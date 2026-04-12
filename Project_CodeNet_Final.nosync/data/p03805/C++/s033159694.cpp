#include <bits/stdc++.h>
#define ll long long
ll mod=1000000007;
#define vl vector<ll>
#define pl pair<ll,ll>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,b) for(ll i=0;i<b;i++)
#define RFOR(i,a,b) for(ll i=b-1;i>=a;i--)
#define rsort(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(),(v).end()
using namespace std;

int main(){
    ll n,m,a,b,ans=0;
    ll array[]={0,1,2,3,4,5,6,7};
    bool root[8][8];
    rep(i,8)rep(j,8)root[i][j]=false;

    cin>>n>>m;
    rep(i,m){
        cin>>a>>b;
        a--;b--;
        root[a][b]=1;
        root[b][a]=1;
    }
    do{
        bool flag=1;
        for(int i=0; i<n-1; i++){
           if(root[array[i]][array[i+1]]==0)flag=0;
        }
        if(flag==1)ans++;
    }while(next_permutation(array+1,array+n));
    cout<<ans<<endl;
}