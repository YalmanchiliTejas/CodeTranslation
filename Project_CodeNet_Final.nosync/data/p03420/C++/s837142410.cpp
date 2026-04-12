

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/
#define rep(i,l,r) for(int i=l;i<=r;i++)
const double EPS=1E-8;

////////////////////////////////////////
ll max(ll a,ll b){return a>b?a:b;}

int main(){
    ll n,k;cin>>n>>k;
    ll ans=0;
    if(k==0){
        cout<<(ll)n*n;
        return 0;
    }
    rep(b,1,n){
        ans+=max(0,n/b*(b-k));
        ans+=max(0,n%b+1-k);
    }
    cout<<ans<<endl;
    return 0;
}
