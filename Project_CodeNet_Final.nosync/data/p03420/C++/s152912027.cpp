#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int main(){
    ll n,k;
    cin>>n>>k;
    ll sum=0;
    if(k==0) {
        cout<<n*n<<endl;
        return 0;
    } 
    for(ll b=k+1;b<=n;++b){
        sum+=n/b*(b-k);
        sum+=max(0ll,n%b-k+1);
    }
    cout<<sum<<endl;
    return 0;
}