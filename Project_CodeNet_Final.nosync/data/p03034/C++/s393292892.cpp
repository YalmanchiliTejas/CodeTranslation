#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll ,ll>;
const ll INF = 1LL<<61LL;
const ll MOD = 1e9+7;

int main(){
	ll N;
	cin >> N;
	vector<ll> s(N);
	for(int i=0;i<N;i++)
		cin >> s[i];
	for(int i=0;i<N/2;i++)
		s[i] += s[N-1-i];
	ll ans = 0;
	vector<bool> visited(N, false);
	for(ll step = 1;step<N;step++){
		ll now = 0;
		ll sum = 0;
		while(now + step < N-1){
			now += step;
			ll idx = min(now, N-1-now);
			if(visited[idx] || N-1-now-step <= 0 || (N % 2 && now == N / 2))
				break;
			visited[idx] = true;
			sum += s[idx];
			ans = max(ans, sum);
		}
		now = 0;
    while(now + step < N-1){
      now += step;
      ll idx = min(now, N-1-now);
      visited[idx] = false;
    }
	}
	cout << ans << endl;
	return 0;
}
