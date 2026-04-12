#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll arr[n];
    ll su[n];
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    }


    su[0] = arr[0];
    ll mod = 1e9+7;
    
    for(int i=1;i<n;i++){
    	su[i] = arr[i] + su[i-1];
    	su[i]%=mod;
    }

    ll ans = 0;
    for(int i=0;i<(n-1);i++){
    	ans+= (arr[i] * (su[n-1]-su[i] + mod)%mod)%mod;
    	ans%=mod;
    }
    cout<<ans<<"\n";
    return 0;
}
