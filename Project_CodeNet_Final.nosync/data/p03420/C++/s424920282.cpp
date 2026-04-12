#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define F first
#define S second
ll n,k,ans;
int main(void){
    cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    for(ll i=k+1;i<=n;i++){
        ans+=(n/i)*(i-k);
        if(n%i>=k)ans+=n%i-k+1;
    }
    cout<<ans<<endl;
    return 0;
}
