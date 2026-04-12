#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    if(n&1){
    	ll sum = 0, m = -a[0], num = m;
    	for(int i=0;i<n;i+=2) sum += a[i];
    	for(int i=2;i<n;i+=2) m = max(m + a[i-1],0LL) - a[i], num = max(num,m);
    	cout << sum + num <<endl;
    }
    else{
    	vector<ll> b(n+1,0);
    	for(int i=n-2;i>=0;i-=2) b[i] = b[i+2] + a[i+1];
    	ll sum=0,ans=-1e18;
    	for(int i=0;i<n;i+=2) ans = max(ans,sum+b[i]), sum += a[i];
        cout << max(ans,sum) <<endl;
    }
    return 0;
}
