#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF = 0x3f3f3f3f;
const ll mod  = 1e9 + 7;
const ll N = 1e6 + 5;

ll n,a[N],sum,ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	sum=(sum+a[i])%mod;
    }
    for(int i=1;i<=n;i++){
    	sum=(sum-a[i]+mod)%mod;
    	ans=(ans+a[i]*sum%mod)%mod;
    }
    cout<<ans;
    return 0;
}