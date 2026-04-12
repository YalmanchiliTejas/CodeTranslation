#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000000000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll N;
ll A[55];

bool check(ll K){
	ll u = 0;
	rep(i,0,N){
		ll b = A[i]+K;
		if(b<=N-1)continue;
		u += b/(N+1LL);
		b %= N+1LL;
		if(b == N) u++;
	}
	return (K >= u);
}


int main()
{
	cin >> N;
	rep(i,0,N)cin >> A[i];
	ll l=-1,r=INF;
	while(r-l>1){
		ll m = (l+r)/2;
		if(check(m))r = m;
		else l = m;
	}
	ll k = r;
	rep(i,0,10000){
		ll li = (ll)i;
		ll t = r - li;
		if(t < 0)break;
		if(check(t))k = t;
	}
	cout << k << endl;
	return 0;
}
