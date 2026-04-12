#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define int ll
#define MOD 1000000007
#define maxn 200001
int N, A[maxn],ss[maxn];

int32_t main()
{
    cin>>N;
    FOR(i,0,N-1) cin>>A[i];
    ss[0] = 0;
    FOR(i,1,N-1){
		ss[i] = (ss[i-1] + A[i-1]) % MOD;
	}
	
	int ans = 0;
	
	FOR(i,0,N-1){
		//cout<<(ss[i] * A[i]) % MOD;
		ans += (ss[i] * A[i]) % MOD; ans %= MOD;
	}
	
	cout<<ans;
    
}
