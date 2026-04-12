#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;
vector<long long int> a;

long long int ans;

int main()
{
	cin >> N;
	a = vector<long long int>(N);
	for (int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	ans = 0;
	while (true){
		sort(a.begin(), a.end(), greater<long long int>());
		
		if (a[0] < N) break;
		
		long long int cnt = a[0] / N;
		long long int dist = a[0] - a[1];
		
		if (dist < cnt){
			cnt = dist + 1;
		}
		
		a[0] -= cnt * N;
		for(int i = 1; i < N; i++){
			a[i] += cnt;
		}
		
		if (cnt < 0) {
			cout << "Error" << endl;
			break;
		}
		
		ans += cnt;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
