#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll cnt=0;
    ll n,k;cin>>n>>k;
    if(k==0)cnt+=n*(n-1)/2;
    else cnt+=(n-k+1)*(n-k)/2;
    REP(i,k+1,n+1){
        cnt+=(i-k)*(max(0LL,n/i-1))+max(0LL,n%i-k+1);
    }
    cout<<cnt<<endl;
}