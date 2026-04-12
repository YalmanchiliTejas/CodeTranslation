#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;

int main(){
	int N;
	cin >> N;
	vector<ll> s(N);
	for(int i = 0; i < N; i++) cin >> s[i];
	ll res = 0;
	for(int i = 1; i < N; i++){
		ll sum = 0;
		vector<bool> visited(N, false);
		for(int j = 0; j * i <= N - 1; j++){
			visited[j * i] = true;
			if(visited[N - 1 - (j * i)]) break;
			if(N - 1 - (j * i) < i) break;
			sum += s[j * i] + s[N - 1 - (j * i)];
			res = max(res, sum);
		}
	}
	cout << res << endl;
	return 0;
}