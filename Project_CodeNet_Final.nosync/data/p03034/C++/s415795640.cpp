#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N; cin >> N;
	int s[N];
	for(int i=0; i<N; i++){
		cin >> s[i];
	}
	ll ans = 0;
	for(int i=1; i<=N-2; i++){
		int t = (N-1)%i;
		int p = (N-1-t)/i;
		int x = t + p * i;
		if(x == N-1) x -= i;
		ll sum = 0;
		int cnt = 1;
		for(int j=x; j>0 && j > i; j=j-i){
			if(j % i == 0){
				if(j <= N-1-j) break;
			}
			sum += s[j];
			sum += s[i*cnt];
			if(sum > ans) ans = sum;
			cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}
