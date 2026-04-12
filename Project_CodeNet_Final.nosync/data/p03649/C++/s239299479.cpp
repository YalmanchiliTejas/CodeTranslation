//E
#include<bits/stdc++.h>
using namespace std;

int n;

vector<long long int> v;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		long long int a;
		scanf("%lld", &a);
		v.push_back(a);
	}
	long long int cost = 0;
	while (*max_element(v.begin(), v.end()) >= (long long int)(n)){
		for (int i = 0; i < v.size(); i++){
			long long int up = max(0LL, v[i] - (n - 1));
			up += n - 1;
			up /= (n);
			v[i] -= up*(n);
			for (int j = 0; j < v.size(); j++){
				if (j != i){
					v[j] += up;
				}
			}
			cost += up;
		}
	}
	printf("%lld\n", cost);
	return 0;
}