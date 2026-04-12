#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int mod = 1e9+7;
/*
#define bigint __int128
__int128 abss(__int128 x){if(x>0)return x;
    return -x;
    }
*/
void solve() {
    int n;cin>>n;
    vector<ll>v(n);
    for(ll &i:v)cin>>i;
    ll ans = 0,sum = 0;
    for(int i = 0;i<n;i++)sum+=v[i];
    
    for(int i = 0;i<n;i++){
	sum-=v[i];
	ans = (ans%mod + ((v[i]%mod)*(sum%mod))%mod)%mod;
	}
	cout<<(ans%mod)<<endl;
    
}
int main()
{boost;
int t;t = 1;//cin>>t;
while(t--){solve();}
}
