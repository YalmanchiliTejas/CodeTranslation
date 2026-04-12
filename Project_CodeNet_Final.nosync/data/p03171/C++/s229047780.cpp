#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MAXN 3000
ll pizza[MAXN];
ll memo[MAXN][MAXN];




ll mangia(ll a, ll b, ll somma) {
    if (a==b) return pizza[a];
    if (memo[a][b]==-1) memo[a][b]=max(somma-mangia(a+1, b, somma-pizza[a]), somma-mangia(a, b-1, somma-pizza[b]));
    return memo[a][b];
}

ll sum=0;

ll contentezza (ll N, ll V[]) {
    for (ll i=0; i<N; i++) {
        pizza[i] = V[i];
        sum+=V[i];
    }
    memset(memo,-1,sizeof(memo));
    return mangia(0, N-1, sum);
}

int main(){
  	ll N;
  	cin >> N;
  	ll a[N];
  	for(ll i = 0;i < N;++i){
      cin >> a[i];
    }

    ll X = contentezza(N,a);
    ll Y = sum - X;
    ll ans = X-Y;

  	cout << ans << endl;
}
