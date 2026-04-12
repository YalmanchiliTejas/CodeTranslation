#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int N; cin>>N;
	ll level[N + 1], patties[N + 1];
	level[0] = patties[0] = 1;
	for(int i = 1; i <= N; i++){
		level[i] = 2*level[i - 1] + 3;
		patties[i] = 2*patties[i - 1] + 1;
	}
	ll X; cin>>X;
	ll ans = 0;
	for(int i = N; i >= 0; i--){
		if(i == 0){
			if(X >= 1)ans++;
		}else{
			if(X <= 1 + level[i - 1]){
				X--;
				continue;
			}else{
				ans += 1 + patties[i - 1];
				X -= 2 + level[i - 1];
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}