#include<bits/stdc++.h>
using namespace std;

//--> definitions
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define RFOR(i,a,b) for(int i=b-1;i>=a;i--)

//--> typedef
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<pii,int> piii;
typedef tuple<int,int,int> tiii;

#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define INF 1e9

const int maxN = 2e5+11;
const int mod = 1e9+7;

ll a[maxN];
ll sum=0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin>>n;
    
    FOR(i,0,n){
        cin>>a[i];
        sum = (sum+ a[i])%mod;
    }
    
    ll ans=0;
    FOR(i,0,n-1){
        sum=(sum-a[i])%mod;
        if(sum<0)
            sum=(sum+mod);
        ans =(ans+ ((a[i] * sum)%mod))%mod;
    }
    
    cout<<ans<<"\n";
    
	return 0;
}